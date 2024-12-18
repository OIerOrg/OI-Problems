// @Author: @qmwneb 
// @Language: C++14 
// @Date: Sun 12/08/2024 
// @Time: 01:53 PM
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr i64 INF = 1e18;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 l, r, k;
    std::cin >> l >> r >> k;
    if (k == 1) {
        std::cout << l << '\n' << 1 << '\n' << l << '\n';
        return 0;
    }
    if (r - l + 1 <= 10) {
        i64 ans = INF, flag = -1;
        for (int i = 1; i < (1 << (r - l + 1)); i++) {
            if (__builtin_popcountll(i) > k) continue;
            i64 res = 0;
            for (int j = 0; j < r - l + 1; j++) {
                if (i & (1 << j)) {
                    res ^= l + j;
                }
            }
            if (res < ans) {
                flag = i;
                ans = res;
            }
        }
        std::cout << ans << '\n' << __builtin_popcountll(flag) << '\n';
        for (int i = 0; i < r - l + 1; i++) {
            if (flag & (1 << i))
            std::cout << i + l << ' ';
        }
        return 0;
    }
    if (k == 2) {
        std::cout << 1 << '\n' << 2 << '\n'
                  << (l + 1) / 2 * 2 << ' '
                  << (l + 1) / 2 * 2 + 1 << '\n';
        return 0;
    }
    if (k >= 4) {
        std::cout << 0 << '\n' << 4 << '\n' 
                  << (l + 3) / 4 * 4 << ' ' 
                  << (l + 3) / 4 * 4 + 1 << ' ' 
                  << (l + 3) / 4 * 4 + 2 << ' ' 
                  << (l + 3) / 4 * 4 + 3 << '\n';
        return 0;
    }
    if (k == 3) {
        for (int i = 0; i <= 40; i++) 
            for (int j = i + 1; j <= 40; j++) {
                i64 x = (1LL << i) | (1ll << j), y = x - 1, z = x ^ y;
                if (x <= r && z >= l) {
                    std::cout << 0 << '\n' << 3 << '\n' << x << ' ' << y << ' ' << z << '\n';
                    return 0;
                }
            }
        std::cout << 1 << '\n' << 2 << '\n'
                  << (l + 1) / 2 * 2 << ' '
                  << (l + 1) / 2 * 2 + 1 << '\n';
    }
    return 0;
}

// Start Time = 01:53 PM
// End Time =  
// Submit Times =