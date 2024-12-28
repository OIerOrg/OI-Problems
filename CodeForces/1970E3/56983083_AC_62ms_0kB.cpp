#include <bits/stdc++.h>

using i64 = long long;
constexpr int mod = 1000000007;

struct Matrix {
    std::vector<std::vector<i64>> val;

    Matrix(int n, int m) : val(n, std::vector<i64>(m, 0)) {}

    Matrix operator*(const Matrix &other) const {
        int n = val.size(), m = other.val[0].size(), p = other.val.size();
        Matrix result(n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < p; ++k) {
                    result.val[i][j] = (result.val[i][j] + val[i][k] * other.val[k][j] % mod) % mod;
                }
            }
        }
        return result;
    }
};

Matrix ksm(Matrix base, int exp) {
    int n = base.val.size();
    Matrix result(n, n);
    for (int i = 0; i < n; ++i) {
        result.val[i][i] = 1;
    }
    while (exp) {
        if (exp % 2) {
            result = result * base;
        }
        base = base * base;
        exp /= 2;
    }
    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n;
    std::cin >> m >> n;
    std::vector<int> s(m + 1), l(m + 1);
    for (int i = 1; i <= m; ++i) {
        std::cin >> s[i];
    }
    for (int i = 1; i <= m; ++i) {
        std::cin >> l[i];
    }

    Matrix base(2, 2);
    for (int i = 1; i <= m; ++i) {
        base.val[0][0] = (base.val[0][0] + 1LL * (s[i] + l[i]) * s[i]) % mod;
        base.val[0][1] = (base.val[0][1] + 1LL * (s[i] + l[i]) * l[i]) % mod;
        base.val[1][0] = (base.val[1][0] + 1LL * s[i] * s[i]) % mod;
        base.val[1][1] = (base.val[1][1] + 1LL * s[i] * l[i]) % mod;
    }

    Matrix res = ksm(base, n - 1);
    i64 f0 = (1LL * s[1] * res.val[0][0] + 1LL * l[1] * res.val[1][0]) % mod;
    i64 f1 = (1LL * s[1] * res.val[0][1] + 1LL * l[1] * res.val[1][1]) % mod;

    i64 ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans = (ans + f0 * (s[i] + l[i]) % mod + f1 * s[i] % mod) % mod;
    }

    std::cout << ans << "\n";
    return 0;
}
