#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

const int N = 3e5 + 5;
i64 n, a[N];
std::set<i64> ans, s;

inline i64 lcm(i64 x, i64 y) {
    return x / std::__gcd(x, y) * y;
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        ans.clear();
        s.clear();
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        
        for (int i = n; i; i--) {
            std::set<i64> now;
            for (auto x : s) {
                if (lcm(x, a[i]) < 1e9) now.insert(lcm(x, a[i]));
            }
            now.insert(a[i]);
            std::swap(now, s);
            for (auto x : s) {
                ans.insert(x);
            }
        }
        
        int lst = 0, res = 0;
        for (auto x : ans) {
            if (x > lst + 1) {
                res = lst + 1;
                break;
            } else {
                lst = x;
            }
        }
        if ((res ? res : lst + 1) == -2147483629) {
            std::cout << res << ' ' << lst << '\n';
        }
        std::cout << (res ? res : lst + 1) << '\n';
    }
    return 0;
}
