#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int N = 2'000'050;
    constexpr int mod = 1'000'000'007;

    std::vector<i64> f(N);
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        ++f[x];
    }

    constexpr int s = (1 << 20) - 1;

    auto transform = [&](int factor) {
        for (int i = 0; i < 20; ++i) {
            for (int j = s; j >= 0; --j) {
                if ((j & (1 << i)) == 0) {
                    f[j] = (f[j] + f[j | (1 << i)] * factor % mod + mod) % mod;
                }
            }
        }
    };

    auto qpow = [](int base, int exp) -> int {
        int result = 1;
        while (exp) {
            if (exp & 1) {
                result = 1LL * result * base % mod;
            }
            base = 1LL * base * base % mod;
            exp >>= 1;
        }
        return result;
    };

    transform(1);

    for (int i = 0; i <= s; ++i) {
        f[i] = qpow(2, f[i]) - 1;
        if (f[i] < 0) {
            f[i] += mod;
        }
    }

    transform(-1);

    std::cout << f[0] << "\n";

    return 0;
} 