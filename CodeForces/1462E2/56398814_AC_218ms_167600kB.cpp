#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int cnt[N], sum[N], c[N][105];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    c[0][0] = 1;
    for (int i = 1; i <= N - 10; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= min(i - 1, 100ll); j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        if (i <= 100) c[i][i] = 1;
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, ans = 0; cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) cnt[i] = sum[i] = 0;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + cnt[i];
        for (int i = 1; i <= n; i++) {
            int l = max(i - k, 1ll);
            int cnt1 = sum[i] - sum[l - 1];
            int cnt2 = sum[i - 1] - sum[l - 1];
            (ans += (c[cnt1][m] - c[cnt2][m]) % mod + mod) %= mod;
        }
        cout << ans << '\n';
    }
	return 0;
}