#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t, x, max = 0;
    std::cin >> t;
    std::vector<int> cnt(t + 1, 0);

    for (int i = 0; i < t; i++) {
        std::cin >> x;
        max = std::max(max, x);
        cnt[x]++;
    }

    x = 1;

    for (int i = 1; i <= max; i++) {
        if (cnt[i] < i * 4) {
            x = i;
            break;
        } 
    }
    
    for (int i = 1; i <= t; i++) {
        if (t % i) continue;
        int n = i, m = t / i, y = n + m - x - max;
        if (abs(n - x) + abs(m - y) == max) {
            std::vector <int> Cnt(t + 1, 0);
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= m; k++) {
                    Cnt[abs(j - x) + abs(k - y)]++;
                }
            }
            bool flag = true;
            for (int j = 0; j <= t; j++) {
                if (Cnt[j] != cnt[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                std::cout << n << ' ' << m << std::endl;
                std::cout << x << ' ' << y << std::endl;
                return 0;
            }
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}
