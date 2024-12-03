#include <bits/stdc++.h>

using i64 = long long;

void solve () {
    int n, m;
    std::cin >> n >> m;

    std::string s, t;
    std::cin >> s >> t;
    std::array <std::vector <int>, 26> vec;

    for (int i = n - 1; i >= 0; i--) {
        vec[s[i] - 'a'].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int x = t[i] - 'a';

        if (vec[x].empty()) {
            std::cout << "NO\n";
            return;
        }

        int p = vec[x].back();
        vec[x].pop_back();

        for (int i = 0; i < x; i++) {
            while (vec[i].size() && vec[i].back() < p) {
                vec[i].pop_back();
            }
        }
    }
    std::cout << "YES\n";
    return;
}

int main() {
#ifdef kimi
    freopen("in.txt", "r", stdin);
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