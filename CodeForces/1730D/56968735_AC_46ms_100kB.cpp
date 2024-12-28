#include <bits/stdc++.h>

using i64 = long long;

void solve () {
    int n, cnt = 0;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    std::reverse(t.begin(), t.end());
    std::array <std::array <bool, 26>, 26> vis;
    vis = {};
    for (int i = 0; i < n; i++) {
        int a = s[i] - 'a';
        int b = t[i] - 'a';
        if (a > b) std::swap (a, b);
        vis[a][b] = 1 - vis[a][b];
    }
    for (int i = 0; i < 26; i++) {
        cnt += vis[i][i];
        for (int j = i + 1; j < 26; j++) {
            if (vis[i][j]) {
                std::cout << "NO\n";
                return;
            }
        }
    }
    if (cnt == 1 || cnt == 0) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#else 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}