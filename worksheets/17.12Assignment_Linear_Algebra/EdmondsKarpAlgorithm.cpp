/**
 * From: http://blog.csdn.net/menxiaoyuan/article/details/51088513
 */
#include<iostream>  
#include<queue>
#include<memory.h>  
using namespace std;  
const int maxn = 205;  
const int inf = 0x7fffffff;  
      
bool visit[maxn];  
int r[maxn][maxn]; //残留网络，初始化为原图  
int pre[maxn];  
int m,n;  
      
bool bfs(int s,int t)  //寻找一条从s到t的增广路，若找到返回true  
{  
    int p;  
    queue<int > q;  
    memset(pre, -1, sizeof(pre));  
    memset(visit, false, sizeof(visit));  
    pre[s] = s;  
    visit[s] = true;  
    q.push(s);  
    while(!q.empty())  
    {  
        p = q.front();  
        q.pop();  
        for(int i = 1; i <= n; i++)  
        {  
            if(r[p][i] > 0 && !visit[i])  
            {  
                pre[i] = p;  
                visit[i] = true;  
                if(i == t)
                    return true;  
                q.push(i);  
            }  
        }  
    }  
    return false;  
}  
  
int EdmondsKarp(int s, int t)  
{  
    int flow = 0,d,i;  
    while(bfs(s, t))  
    {  
        d = inf;  
        for(i = t; i != s; i = pre[i])  
            d = d < r[pre[i]][i] ? d : r[pre[i]][i];  
        for(i = t; i != s; i = pre[i])  
        {  
            r[pre[i]][i] -= d;  
            r[i][pre[i]] += d;  
        }  
        flow += d;  
    }  
    return flow;  
}  
  
  
int main()  
{  
    while(scanf("%d%d", &n, &m)!=EOF)  
    {  
        int u,v,w;  
        memset(r, 0, sizeof(r));///  
        for(int i = 0; i < m; i++)  
        {  
            scanf("%d%d%d", &u, &v, &w);  
            r[u][v] += w;  
        }  
        printf("%d\n", EdmondsKarp(1, n));  
    }  
    return 0;  
}  