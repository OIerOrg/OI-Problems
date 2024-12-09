#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector arr(n + 1, std::vector (m + 1, 0));
    std::vector sum(n + 1, std::vector (m + 1, 0));
    std::vector lmax(n + 1, std::vector (m + 1, 0));
    std::vector rmax(n + 1, std::vector (m + 2, 0));
    std::vector dp(n + 1, std::vector (m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> arr[i][j];
            sum[i][j] = sum[i][j - 1] + arr[i][j];
        }
    }
    auto get = [&](int i, int s, int e) {
        return sum[i][e] - sum[i][s - 1];
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m - k + 1; j++) {
            int now = get(i, j, j + k - 1) + (i == n ? 0 : get(i + 1, j, j + k - 1));
            if (i == 1) {
                dp[i][j] = now;
                continue;
            }
            for (int x = std::max(1, j - k + 1); x <= std::min(j + k - 1, m - k + 1); x++) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][x] + now - get(i, std::max(x, j), std::min(x + k - 1, j + k - 1)));               
            }   
            if (j > k) dp[i][j] = std::max(dp[i][j], lmax[i - 1][j - k] + now); 
            if (j + k <= m) dp[i][j] = std::max(dp[i][j], rmax[i - 1][j + k] + now); 
        }
        for (int j = 1; j <= m - k + 1; j++) {
            lmax[i][j] = std::max(lmax[i][j - 1], dp[i][j]);
        } 
        for (int j = m - k + 1; j >= 1; j--) {
            rmax[i][j] = std::max(rmax[i][j + 1], dp[i][j]);
        }
    }
    int ans = 0;
    for (int j = 1; j <= m - k + 1; j++) {
        ans = std::max(ans, dp[n][j]);
    }
    std::cout << ans << std::endl;
    return 0;
}
