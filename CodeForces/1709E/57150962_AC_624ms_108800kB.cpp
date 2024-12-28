#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, ans = 0;
    std::cin >> n;
    std::vector c(n + 1, 0);
    std::vector dis(n + 1, 0);
    std::vector e(n + 1, std::vector <int>());
    std::vector <std::unordered_set <int>> set(n + 1); 
    for (int i = 1; i <= n; i++) std::cin >> c[i];
    for (int i = 1; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    auto dfs = [&](auto self, int x, int fa) -> void {
        dis[x] = dis[fa] ^ c[x]; 
        set[x].insert(dis[x]);
        bool flag = false;
        for (int v : e[x]) {
            if (v != fa) {
                self (self, v, x);
                if (set[x].size() < set[v].size()) swap (set[x], set[v]);
                for (auto i : set[v])
                    if (set[x].count(i ^ c[x]) > 0)
                        flag = true;
                for (auto i : set[v]) {
                    set[x].insert(i);
                }
            }
        }
        if (flag) {
            ans++;
            set[x].clear();
        }
    };
    dfs (dfs, 1, 1);
    std::cout << ans << '\n';
    return 0;
}