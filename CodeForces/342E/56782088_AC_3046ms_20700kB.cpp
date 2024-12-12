#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int t = sqrt(n); // 分块大小

    std::vector<std::vector<int>> edge(n);
    std::vector<std::array<int, 20>> fa(n);
    std::vector<int> dep(n), dis(n, 1e9);
    std::vector<bool> red(n); 
    red[0] = true; // 初始红色节点

    for (int i = 0; i < n - 1; i++) { 
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    std::function<void(int, int)> dfs = [&](int x, int f) {
        fa[x][0] = f;
        dep[x] = dep[f] + 1;
        for (int i = 1; i < 20; i++) {
            fa[x][i] = fa[fa[x][i - 1]][i - 1];
        }
        for (int i : edge[x]) {
            if (i != f) {
                dfs(i, x); 
            }
        }
    };
    dfs(0, 0);

    std::function<int(int, int)> lca = [&](int a, int b) {
        if (dep[a] < dep[b]) {
            std::swap(a, b);
        }
        for (int i = 19; i >= 0; i--) {
            if (dep[fa[a][i]] >= dep[b]) {
                a = fa[a][i];
            }
        }
        if (a == b) return a;
        for (int i = 19; i >= 0; i--) {
            if (fa[a][i] != fa[b][i]) {
                a = fa[a][i];
                b = fa[b][i];
            }
        }
        return fa[a][0];
    };

    std::function<int(int, int)> distance = [&](int a, int b) {
        int LCA = lca(a, b);
        return dep[a] + dep[b] - 2 * dep[LCA];
    };

    std::function<void()> update = [&]() {
        std::queue<int> q;
        std::fill(dis.begin(), dis.end(), 1e9);
        for (int i = 0; i < n; i++) {
            if (red[i]) {
                q.push(i);
                dis[i] = 0;
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : edge[u]) {
                if (dis[v] > dis[u] + 1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
    };

    std::vector<int> now;
    for (int i = 0; i < m; i++) {
        if (i % t == 0) {
            update();
            now.clear();
        }
        int op, x;
        std::cin >> op >> x;
        x--;
        if (op == 1) {
            red[x] = true;
            now.push_back(x);
        } else {
            int ans = dis[x];
            for (int u : now) {
                ans = std::min(ans, distance(x, u));
            }
            std::cout << ans << '\n';
        }
    }

    return 0;
}
