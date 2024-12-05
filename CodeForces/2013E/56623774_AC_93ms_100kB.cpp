#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        i64 n, allgcd = 0, ans = 0, nowgcd = 0; 
        std::cin >> n;
        std::vector <i64> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            allgcd = std::__gcd(allgcd, a[i]);
        }
        sort (a.begin(), a.end());
        ans = a[0], nowgcd = a[0];
        for (int i = 1; i < n; i++) {
            if (nowgcd == allgcd) {
                ans += allgcd;
            } else {
                for (int j = i + 1; j < n; j++) {
                    if (std::__gcd(nowgcd, a[j]) < std::__gcd(nowgcd, a[i])) {
                        std::swap (a[i], a[j]);
                    }
                }
                nowgcd = std::__gcd(nowgcd, a[i]);
                ans += nowgcd;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}