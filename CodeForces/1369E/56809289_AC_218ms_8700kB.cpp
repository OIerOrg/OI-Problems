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

    std::vector<int> w(n + 1), t(n + 1), stk;
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    std::vector<bool> vis(m + 1, false);

    for (int i = 1; i <= n; i++) {
        std::cin >> w[i];
    }

    for (int i = 1; i <= m; i++) {
        int x, y;
        std::cin >> x >> y;
        t[x]++;
        t[y]++;
        adj[x].emplace_back(y, i);
        adj[y].emplace_back(x, i);
    }

    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (t[i] <= w[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto [neighbor, index] : adj[x]) {
            if (!vis[index]) {
                vis[index] = true;
                stk.push_back(index);
                if (--t[neighbor] <= w[neighbor]) {
                    q.push(neighbor);
                }
            }
        }
    }

    if (stk.size() < m) {
        std::cout << "DEAD\n";
    } else {
        std::cout << "ALIVE\n";
        std::reverse(stk.begin(), stk.end());
        for (int edge : stk) {
            std::cout << edge << ' ';
        }
    }

    return 0;
}
