#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 N = 200007;
constexpr i64 LOG = 18;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        i64 n;
        std::cin >> n;

        std::vector<i64> a(n + 1), b(n + 1);
        std::vector<std::vector<i64>> st(n + 1, std::vector<i64>(LOG));
        std::vector<std::vector<i64>> ans(n + 1, std::vector<i64>(64, 0));

        for (i64 i = 1; i <= n; ++i) std::cin >> a[i];
        for (i64 i = 1; i <= n; ++i) std::cin >> b[i];

        auto build = [&]() {
            for (i64 i = 1; i <= n; ++i) st[i][0] = i;
            for (i64 j = 1; (1 << j) <= n; ++j) {
                for (i64 i = 1; i + (1 << j) - 1 <= n; ++i) {
                    i64 l = st[i][j - 1];
                    i64 r = st[i + (1 << (j - 1))][j - 1];
                    st[i][j] = (b[l] <= b[r] ? l : r);
                }
            }
        };

        auto query = [&](i64 L, i64 R) -> i64 {
            i64 len = R - L + 1;
            i64 k = std::log2(len);
            i64 l = st[L][k];
            i64 r = st[R - (1 << k) + 1][k];
            return (b[l] <= b[r] ? l : r);
        };

        std::function<i64(i64, i64)> dfs = [&](i64 l, i64 r) -> i64 {
            if (l > r) return 0;
            if (l == r) {
                ans[l][0] = a[l];
                for (int i = 1; i < 64; ++i) ans[l][i] = (ans[l][i - 1] - 1) / b[l] + 1;
                return l;
            }
            i64 u = query(l, r);
            i64 pl = dfs(l, u - 1), pr = dfs(u + 1, r);
            for (int i = 0; i < 64; ++i) {
                ans[u][i] = std::max(ans[pl][0], ans[pr][i]);
            }
            for (int i = 0; i < 64; ++i) {
                for (int j = 0; i + j < 64; ++j) {
                    ans[u][i + j] = std::min(ans[u][i + j], std::max(ans[pl][i], ans[pr][j]));
                }
            }
            ans[u][0] = std::max(ans[u][0], a[u]);
            for (int i = 1; i < 64; ++i) {
                ans[u][i] = std::min(std::max(ans[u][i], a[u]), (ans[u][i - 1] - 1) / b[u] + 1);
            }
            return u;
        };

        build();
        i64 root = dfs(1, n);

        for (int i = 0; i < 64; ++i) {
            if (ans[root][i] == 1) {
                std::cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}
