#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1005;

void solve () {
    i64 n, ans = 0;
    std::cin >> n;
    std::map <i64, int> s;
    for (i64 i = 1, a, ne = 1, del = 0; i <= n; i++) {
        std::cin >> a;
        ne ^= 1;
        del = -del + a;
        ne ? s[del - a]++ : s[a - del]++;
        while (s.size()) {
            if (ne) {
                auto it = *s.rbegin();
                if (it.first > del) s.erase(--s.end());
                else break;
            } else {
                auto it = *s.begin();
                if (it.first < -del) s.erase(s.begin());
                else break;
            }
        }
        ans += ne ? s[del] : s[-del];
    }
    std::cout << ans << std::endl;
}

int main() {
#ifdef qmwneb
    freopen("in.txt", "r", stdin);
#endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}