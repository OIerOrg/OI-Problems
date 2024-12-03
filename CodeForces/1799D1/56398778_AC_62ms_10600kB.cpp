#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int T, n, m;
int a[N], b[N], c[N];
int vis[N], lst[N];
long long dp[N], s[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> a[i], lst[i] = vis[a[i]], vis[a[i]] = i;
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        for (int i = 1; i <= m; i++)
            cin >> c[i];
        for (int i = 1; i <= n; ++i)
            s[i] = s[i - 1] + (a[i] == a[i - 1] ? c[a[i]] : b[a[i]]);
        for (int i = 1; i <= n; ++i)
            dp[i] = min(dp[i - 1] + b[a[i]], lst[i] ? lst[i] == i - 1 ? dp[i - 1] + c[a[i]] : dp[lst[i] + 1] + c[a[i]] + s[i - 1] - s[lst[i] + 1] : s[i]);
        cout << dp[n] << '\n';
        for (int i = 1; i <= n; ++i) vis[a[i]] = 0;
    }
    return 0;
}