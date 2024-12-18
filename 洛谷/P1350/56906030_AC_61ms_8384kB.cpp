#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c, d, m;
    constexpr int mod = 100003;
    std::cin >> a >> b >> c >> d >> m;

    int n = a + c;
    std::vector<int> v(n + 1);
    for (int i = 1; i <= c; ++i) {
        v[i] = d;
    }
    for (int i = 1; i <= a; ++i) {
        v[c + i] = d + b;
    }

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1, 0));
    f[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        f[i][0] = 1;
        for (int j = 1; j <= m; ++j) {
            f[i][j] = f[i - 1][j];
            if (j <= v[i]) {
                f[i][j] = (f[i][j] + 1LL * f[i - 1][j - 1] * (v[i] - j + 1)) % mod;
            }
        }
    }

    std::cout << f[n][m] << "\n";
    return 0;
}
