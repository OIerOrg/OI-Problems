#include <bits/stdc++.h>

using i64 = long long;

i64 qpow(int a, int b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, x;
    std::cin >> n >> m >> x;

    std::vector<std::vector<char>> c(n + 1, std::vector<char>(m + 1));
    std::vector<std::vector<i64>> a(n + 1, std::vector<i64>(m + 1));
    std::vector<std::vector<i64>> dep(n + 1, std::vector<i64>(m + 1));
    bool flag = false;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> c[i][j];
            a[i][j] = c[i][j] - '0';
        }
    }
    for (int i = 2; i <= n; ++i) {
        dep[i][1] = dep[i - 1][1] + qpow(a[i][1] - a[i - 1][1], x);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            dep[i][j] = dep[i][j - 1] + qpow(a[i][j] - a[i][j - 1], x);
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dep[i][j] - dep[i + 1][j] + qpow(a[i + 1][j] - a[i][j], x) != 0) {
                flag = true;
            }
        }
    }
    int q;
    std::cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (flag) {
            std::cout << "INVALID\n";
        } else {
            std::cout << dep[x1][y1] - dep[x2][y2] << '\n';
        }
    }

    return 0;
}
