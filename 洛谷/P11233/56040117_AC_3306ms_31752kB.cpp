#include <bits/stdc++.h>

#define int long long
#define rint register int
#define endl '\n'
#define m(a) memset(a, 0, sizeof a)

using namespace std;

const int N = 1e6 + 5;

int n, T;
int a[N], lst[N], f[N];
int s[N], ans; 

signed main() 
{
	cin >> T;
	while (T--) 
	{
		cin >> n;
		m(a), m(lst), m(f), m(s);
		for (rint i = 1; i <= n; i++) cin >> a[i];
		for (rint i = 2; i <= n; i++) s[i] = (a[i] == a[i - 1] ? s[i - 1] + a[i] : s[i - 1]);
		for (rint i = 1; i <= n; i++) 
		{
			f[i] = f[i - 1];
			if (lst[a[i]]) f[i] = max(f[i], f[lst[a[i]] + 1] + a[i] + s[i] - s[lst[a[i]] + 1]);
			lst[a[i]] = i;
		}
		cout << f[n] << endl;
	} 
	return 0;
}
