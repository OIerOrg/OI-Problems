#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int N = 1e5 + 10;
constexpr int M = 15;

int arr[M][N];
i64 f[N];

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int p = i - 1; p >= std::max(i - k, 0); p--) {
                f[p + 1] = std::max(f[p + 1], arr[j][i] + f[p]);
            } 
        }
    }
    std::cout << f[m - k + 1];
    return 0;
}