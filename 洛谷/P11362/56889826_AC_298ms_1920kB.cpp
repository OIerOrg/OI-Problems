#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 1e9 + 7;

constexpr i64 qpow (i64 x, i64 y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    i64 res = qpow(x, y / 2);
    res = res * res % mod;
    if (y & 1) res = res * x % mod;
    return res;
}

void solve () {
    i64 n, m, v, ans = 1;
    std::cin >> n >> m >> v;
    std::vector <std::pair <i64, i64>> q(m);
    for (int i = 0; i < m; i++) {
        std::cin >> q[i].first >> q[i].second;
    }
    std::sort (q.begin(), q.end(), [](std::pair <i64, i64> a, std::pair <i64, i64> b) { return a.first < b.first; });
    for (int i = 1; i < m; i++) {
        if (q[i].first == q[i - 1].first) {
            if (q[i].second != q[i - 1].second) {
                std::cout << 0 << std::endl;
                return;
            }
            continue;
        } 
        i64 a = qpow(v, 2 * q[i].first - 2 * q[i - 1].first);
        i64 b = qpow(v, q[i].first - q[i - 1].first - 1) * (v - 1) % mod;
        (ans *= (a - b + mod) % mod) %= mod;
    }
    (ans *= qpow(v, 2 * q[0].first - 2)) %= mod;
    (ans *= qpow(v, 2 * n - 2 * q[m - 1].first)) %= mod;
    std::cout << ans << std::endl;
}

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
        solve();
    }
    return 0;
}
