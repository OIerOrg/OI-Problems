#include <bits/stdc++.h>

using i64 = long long;

constexpr int M = 2e5 + 10;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, cnt = 0;
    std::unordered_map<int, int> lst;
    std::unordered_map<int, int> count;
    std::cin >> m;

    std::vector<int> n(m);
    std::array<std::vector<int>, M> e;
    for (int i = 0; i < m; i++) {
        std::cin >> n[i];
        for (int j = 0; j < n[i]; j++) {
            int x;
            std::cin >> x;
            cnt++;
            count[x]++;
            if (lst[x] && count[x] % 2 == 0) {
                e[cnt].push_back(lst[x]);
                e[lst[x]].push_back(cnt);
            }
            if (j & 1) {
                e[cnt].push_back(cnt - 1);
                e[cnt - 1].push_back(cnt);
            }
            lst[x] = cnt;
        }
    }

    std::vector<bool> vis(cnt + 1, false);
    std::vector<bool> ans(cnt + 1, false);

    std::function<void(int, int)> dfs = [&](int x, int fa) {
        ans[x] = !ans[fa];
        vis[x] = true;
        for (int i : e[x]) {
            if (i != fa && !vis[i]) {
                dfs(i, x);
            }
        }
    };

    bool ok = true;
    for (auto [a, b] : count) {
        if (b & 1) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES\n";
    for (int i = 1; i <= cnt; i++) {
        if (!vis[i]) {
            dfs(i, 0);
        }
    }

    cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n[i]; j++) {
            std::cout << (ans[++cnt] ? 'L' : 'R');
        }
        std::cout << '\n';
    }

    return 0;
}
