#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;
class tile_type
{
public:
	int number;
	char suit;
};

inline bool operator <(tile_type a, tile_type b)
{
	if (a.suit != b.suit) return a.suit < b.suit;
	else return a.number < b.number;
}

inline bool operator ==(tile_type a, tile_type b)
{
	return a.number == b.number && a.suit == b.suit;
}
class component_type
{
public:
	char suit;
	int kind;
	int number;
};

vector<tile_type> declared, hidden, holding;
map<tile_type, int> ans;
int total_component;
component_type cpn_list[100];

void init(char *s1, char* s2)
{
	declared.clear(); hidden.clear();
	int len = strlen(s1);
	int i;
	tile_type temp;
	for (i=0;i<len;i+=2)
	{
		temp.number = s1[i] - '0';
		if (s1[i + 1] == 'D') temp.suit = 0;
		else if (s1[i + 1] == 'B') temp.suit = 1;
		else temp.suit = 2;
		hidden.push_back(temp);
	}

	if (s2[0] == 'N') return;
	len = strlen(s2);
	for (i=0;i<len;i+=2)
	{
		temp.number = s2[i] - '0';
		if (s2[i + 1] == 'D') temp.suit = 0;
		else if (s2[i + 1] == 'B') temp.suit = 1;
		else temp.suit = 2;
		declared.push_back(temp);
	}
}

bool read_data()
{
	char s1[100],s2[100];
	if (scanf("%s%s",&s1,&s2) != 1)
	{
		init(s1,s2);
		return true;
	}
	else return false;
}

int max_score;
bool used[100];

int calc_left(int s)
{
	int cnt = 0,i;
	for (i=0;i<hidden.size();i++)
	{
		if (!used[i]) cnt++;
		if (cnt > 2) break;
	}
	return cnt;
}

bool check_chunkious()
{
	int i;
	for (i=1;i<=total_component;i++) if (cpn_list[i].kind == 2) return false;
	return true;
}

bool check_royal()
{
	int i;
	for (i=0;i<holding.size();i++) if (holding[i].number != 2 && holding[i].number != 5 && holding[i].number != 8) return false;
	return true;
}

bool check_top_down()
{
	int i;
	for (i=1;i<=total_component;i++)
	{
		if (cpn_list[i].kind == 0 || cpn_list[i].kind == 1)
		{
			if (cpn_list[i].number != 1 && cpn_list[i].number != 9) return false;
		}
		if (cpn_list[i].kind == 2)
		{
			if (cpn_list[i].number != 1 && cpn_list[i].number != 7) return false;
		}
	}

	for (i=0;i<declared.size();i++) if (declared[i].number != 1 && declared[i].number != 9) return false;
	return true;
}

void calc_score()
{
	int basic_score = 1;
	bool flag_chunkious = check_chunkious();
	bool flag_royal = false;
	if (flag_chunkious) flag_royal = check_royal();
	bool flag_top_down = check_top_down();
	if (flag_chunkious) basic_score++;
	if (flag_royal) basic_score+=2;
	if (flag_top_down) basic_score+=2;
	max_score = max(max_score,basic_score);
}

int left_before(int s)
{
	int cnt = 0,i;
	for (i=0;i<s;i++)
	{
		if (!used[i]) cnt++;
		if (cnt > 2) break;
	}
	return cnt;
}
void dfs(int s)
{
	if (used[s])
	{
		dfs(s + 1);
		return;
	}
	if (calc_left(s) == 2)
	{
		int i,j;
		for (i=0;i<hidden.size();i++) if (!used[i]) break;
		for (j=i+1;j<hidden.size();j++) if (!used[j]) break;
		tile_type a = hidden[i],  b = hidden[j];
		if (!(a==b)) return;
		component_type cpn;
		cpn.kind = a.suit;
		cpn.number = a.number;
		cpn.kind = 0;
		cpn_list[++total_component] = cpn;
		calc_score();
		total_component--;
	}
	else
	{
		if (left_before(s) > 2) return;
		int i,j;
		component_type cpn;
		for (i=s+1;i<hidden.size();i++) if (!used[i]) 
			for (j=i+1;j<hidden.size();j++) if (!used[j])
			{
				if (hidden[s] == hidden[i] && hidden[s] == hidden[j])
				{
					used[s] = used[i] = used[j] = true;
					cpn.kind = 1;  cpn.number = hidden[s].number; cpn.suit = hidden[s].suit;
					cpn_list[++total_component] = cpn;
					dfs(s + 1);
					total_component--;
					used[s] = used[i] = used[j] = false;
				}
				if ((hidden[s].suit) == (hidden[i].suit) && (hidden[s].suit) == (hidden[j].suit) && (hidden[i].number) == (hidden[s].number + 1) && (hidden[j].number) == (hidden[s].number + 2))
				{
					used[s] = used[i] = used[j] = true;
					cpn.kind = 2;  cpn.number = hidden[s].number; cpn.suit = hidden[s].suit;
					cpn_list[++total_component] = cpn;
					dfs(s + 1);
					total_component--;
					used[s] = used[i] = used[j] = false;
				}
			}
		dfs(s + 1);
	}
}

void preparation_for_dfs()
{
	memset(used,false,sizeof(used));
	total_component = 0;
}

void check_seven_couples()
{
	if (!declared.empty()) return;
	int i;
	bool flag = true;
	for (i=0;i<14;i+=2)
		if (!(hidden[i] == hidden[i + 1]))
		{
			flag = false;
			break;
		}
	if (flag)
	{
		bool top_down_flag = true;
		for (i=0;i<14;i++) if (hidden[i].number != 1 && hidden[i].number != 9) top_down_flag = false;
		if (top_down_flag)
		{
			if (max_score < 5) max_score = 5;
		}
		else
		{
			if (max_score < 3) max_score = 3;
		}
	}
}

void check_dragons()
{
	map<tile_type,int> table;
	table.clear();
	int i,cnt = 0;
	for (i=0;i<holding.size();i++) table[holding[i]]++;
	map<tile_type,int> ::iterator it;
	for (it = table.begin(); it != table.end(); it++) if (it->second == 4) cnt++;
	max_score += cnt;
}

void check_purely()
{
	bool res = true;
	int i;
	for (i=1;i<holding.size();i++) if (holding[i].suit != holding[i - 1].suit) res = false;
	if (res) max_score += 2;
}

bool check_trivial()
{
	set<int> suits;
	suits.clear();
	int i;
	for (i=0;i<holding.size();i++) suits.insert(holding[i].suit);
	if (suits.size() == 3) return false;

	map<tile_type,int> table;
	table.clear();
	int cnt = 0;
	for (i=0;i<holding.size();i++) table[holding[i]]++;
	map<tile_type,int> ::iterator it;
	for (it = table.begin(); it != table.end(); it++) if (it->second > 4) return false;

	return true;
}

int analysis()
{
	max_score = 0;
	vector<tile_type> temp_hidden = hidden;
	sort(hidden.begin(),hidden.end());
	sort(declared.begin(),declared.end());
	holding.clear();
	int i;
	for (i=0;i<hidden.size();i++) holding.push_back(hidden[i]);
	for (i=0;i<declared.size();i++) holding.push_back(declared[i]);

	if (check_trivial())
	{
		preparation_for_dfs();
		dfs(0);
		check_seven_couples();
		if (max_score != 0)
		{
			check_dragons();
			check_purely();
		}
	}

	hidden = temp_hidden;
	return max_score;
}

void work_ans()
{
	ans.clear();
	int i,j,temp_score;
	tile_type temp;
	for (i=0;i<3;i++)
		for (j=1;j<10;j++)
		{
			temp.number = j; temp.suit = i;
			hidden.push_back(temp);
			temp_score = analysis();
			if (temp_score != 0) ans[temp] = temp_score;
			hidden.pop_back();
		}
}

inline char change(int s)
{
	if (s == 0) return 'D';
	else if (s == 1) return 'B';
	else return 'M';
}

void show_ans()
{
	if (ans.empty())
	{
		printf("NONE\n");
		return;
	}
	map<tile_type, int> ::iterator it;
	for (it = ans.begin(); it != ans.end(); it++) printf("%d%c: %d\n",it->first.number, change(it->first.suit), it->second);
}
int main()
{
	int i,t;
	scanf("%d",&t);
	for (i=1;i<=t;i++)
	{
		printf("Case #%d:\n",i);
		read_data();
		work_ans();
		show_ans();
	}
	return 0;
}
