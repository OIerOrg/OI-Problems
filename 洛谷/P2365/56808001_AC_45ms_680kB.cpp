#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, s;
    std::cin >> n >> s;

    std::vector<i64> t(n + 1), f(n + 1), st(n + 1), sf(n + 1), dp(n + 1, 1e18);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        std::cin >> t[i] >> f[i];
        st[i] = st[i - 1] + t[i];
        sf[i] = sf[i - 1] + f[i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i] = std::min(dp[i], dp[j - 1] + st[i] * (sf[i] - sf[j - 1]) + s * (sf[n] - sf[j - 1]));

    std::cout << dp[n] << "\n";
    return 0;
}
