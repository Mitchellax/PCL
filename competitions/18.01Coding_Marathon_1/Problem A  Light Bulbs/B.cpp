/*
 * B.cpp
 *
 *  Created on: 2010-5-13
 *      Author: stm
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 500;
int s[MAXN], t[MAXN], a[MAXN], b[MAXN], n, best;
struct BigNum
{
	int len, s[MAXN];
}st, ed, ans, ZERO, ONE, TWO;

BigNum Multi(const BigNum &a, const BigNum &b)        // BigNum * BigNum
{
    int i,j;
    BigNum c;
    memset(c.s,0,sizeof(c.s));
    c.len = a.len+b.len;
    for (i = 1; i <= a.len; i++)
        for (j = 1; j <= b.len; j++) c.s[i+j-1] += a.s[i]*b.s[j];
    for (i = 1; i < c.len; i++)
    { c.s[i+1] += c.s[i]/10; c.s[i] %= 10; }
    while (c.s[i])
    { c.s[i+1] = c.s[i]/10; c.s[i] %= 10; i++; }
    while (i > 1 && !c.s[i]) i--; c.len = i;
    return c;
}

BigNum Plus(const BigNum &a, const BigNum &b)        // BigNum + BigNum
{
    int i;
    BigNum c;
    c.s[1] = 0;
    for (i = 1; i <= a.len || i <= b.len || c.s[i]; i++)
    {
        if (i <= a.len) c.s[i] += a.s[i];
        if (i <= b.len) c.s[i] += b.s[i];
        c.s[i+1] = c.s[i]/10; c.s[i] %= 10;
    }
    c.len = i-1; if (c.len == 0) c.len = 1;
    return c;
}

BigNum Subtract(const BigNum &a, const BigNum &b)   // BigNum - BigNum
{
    BigNum c;
    for (int i = 1, j = 0; i <= a.len; i++)
    {
        c.s[i] = a.s[i]-j;
        if (i <= b.len) c.s[i] -= b.s[i];
        if (c.s[i] < 0)
        { j = 1; c.s[i] += 10; } else j = 0;
    }
    c.len = a.len; while (c.len > 1 && !c.s[c.len]) c.len--;
    return c;
}

BigNum Change(char ss[MAXN])						// String -> BigNum
{
	BigNum ret;
	ret.len = strlen(ss);
	for (int i = 1; i <= ret.len; ++i) ret.s[i] = ss[ret.len - i] - '0';
	return ret;
}

int Comp(const BigNum &a, const BigNum &b)			// Compare BigNum and BigNum
{
	if (a.len > b.len) return 1;
	if (a.len < b.len) return -1;
	int i = a.len;
	while ((i > 1) && (a.s[i] == b.s[i])) --i;
	return a.s[i] - b.s[i];
}

BigNum Div(const BigNum &a, const BigNum &b)		// BigNum / BigNum
{
	int i, j;
	BigNum d, c;
	d.len = 1; d.s[1] = 0;
	for (i = a.len; i > 0; --i)
	{
		if (!(d.len == 1 && d.s[1] == 0))
		{
			for (j = d.len; j > 0; --j)
				d.s[j + 1] = d.s[j];
			++d.len;
		}
		d.s[1] = a.s[i]; c.s[i] = 0;
		while ((j = Comp(d, b)) >= 0)
		{
			d = Subtract(d, b); ++c.s[i];
			if (j == 0) break;
		}
	}
	c.len = a.len; while ((c.len > 1) && (c.s[c.len] == 0)) --c.len;
	return c;
}

BigNum Mod(const BigNum &a, const BigNum &b)		// BignNum % BigNum
{
	return Subtract(a, Multi(Div(a, b), b));
}

void Show(const BigNum &a)							// Print BigNum
{
    for (int i = a.len; i >= 1; i--) printf("%d",a.s[i]);
    puts("");
}

void calc()
{
	int tot = 0;
	BigNum now = ZERO;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; ++i)
	{
		now = Multi(now, TWO);
		if (a[i - 1] != b[i - 1])
		{
			tot++;
			now = Plus(now, ONE);
			for (int j = i - 1; j <= i + 1; ++j) a[j] = 1 - a[j];
		}
	}
	if (a[n] != b[n]) return;
	if ((tot < best) || (tot == best && Comp(now, ans) < 0))
	{
		best = tot; ans = now;
	}
}

int main()
{
	freopen("B.in", "r", stdin);
	int cases = 0;
	char s1[MAXN], s2[MAXN];
	ZERO.len = ONE.len = TWO.len = 1;
	ZERO.s[1] = 0; ONE.s[1] = 1; TWO.s[1] = 2;
	while (scanf("%s %s", &s1, &s2))
	{
		if (strlen(s1) == 1 && s1[0] == '0' && strlen(s2) == 1 && s2[0] == '0') break;
		n = 0;
		int m = 0;
		memset(s, 0, sizeof(s));
		memset(t, 0, sizeof(t));
		BigNum tmp;

		st = Change(s1), ed = Change(s2);
		while (Comp(st, ZERO) > 0)
		{
			tmp = Mod(st, TWO);
			s[++m] = tmp.s[1];
			st = Div(st, TWO);
		}
		n = max(n, m);
		m = 0;
		while (Comp(ed, ZERO) > 0)
		{
			tmp = Mod(ed, TWO);
			t[++m] = tmp.s[1];
			ed = Div(ed, TWO);
		}
		n = max(n, m);
		for (int i = 1; i <= n; ++i) b[n - i + 1] = s[i] ^ t[i];

		best = n + 1;
		b[0] = 0;
		calc();
		b[0] = 1;
		calc();

		if (cases) puts("");
		printf("Case Number %d: ", ++cases);
		if (best > n) puts("impossible");
		else Show(ans);
	}
	return 0;
}
