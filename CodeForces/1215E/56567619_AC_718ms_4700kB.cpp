// start time: 12:30
// solution: true
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::cin >> n;

    std::vector cnt(20, 0);
    std::vector w(20, std::vector (20, i64(0)));
    std::vector f(1 << 20, i64(1e18));
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        x--;
        cnt[x]++;
        for (int j = 0; j < 20; j++) {
            w[j][x] += cnt[j];
        }
    }
    f[0] = 0;
    for (int i = 1; i < (1 << 20); i++) {
        for (int u = 0; u < 20; u++) {
            if ((1 << u) & i) {
                int j = (1 << u) ^ i;
                i64 sum = 0;
                for (int v = 0; v < 20; v++) {
                    if ((1 << v) & j) {
                        sum += w[u][v];
                    }
                }
                f[i] = std::min(f[i], f[j] + sum);
            }
        }
    }
    std::cout << f[(1 << 20) - 1] << std::endl;
    return 0;
}