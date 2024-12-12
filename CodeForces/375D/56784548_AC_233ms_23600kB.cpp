#include <bits/stdc++.h>

using i64 = long long;

constexpr int Maxn = 1e5 + 5;
constexpr int Maxm = 2e5 + 5;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> c(n + 100);
    for (int i = 1; i <= n; ++i) {
        std::cin >> c[i];
    }

    std::vector<std::vector<int>> adj(n + 100);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<std::vector<std::pair<int, int>>> queries(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, k;
        std::cin >> u >> k;
        queries[u].emplace_back(i, k);
    }

    std::vector<int> fat(n + 100), sze(n + 100), son(n + 100);
    std::vector<int> L(n + 100), R(n + 100), rev(2 * n + 100);
    int tot = 0;

    // First DFS to calculate L, R, sze, son
    std::function<void(int)> DfsFir = [&](int u) {
        sze[u] = 1;
        L[u] = ++tot;
        rev[tot] = u;
        for (int v : adj[u]) {
            if (v == fat[u]) continue;
            fat[v] = u;
            DfsFir(v);
            sze[u] += sze[v];
            if (sze[son[u]] < sze[v]) son[u] = v;
        }
        R[u] = tot;
    };

    DfsFir(1);

    std::vector<int> col(n + 100), sum(2 * n + 100), ans(m + 100);

    auto add = [&](int u) {
        col[c[u]]++;
        sum[col[c[u]]]++;
    };

    auto del = [&](int u) {
        sum[col[c[u]]]--;
        col[c[u]]--;
    };

    // Second DFS to process queries
    std::function<void(int, bool)> DfsSec = [&](int u, bool iss) {
        for (int v : adj[u]) {
            if (v == fat[u] || v == son[u]) continue;
            DfsSec(v, false);
        }

        if (son[u]) DfsSec(son[u], true);
        add(u);

        for (int v : adj[u]) {
            if (v == fat[u] || v == son[u]) continue;
            for (int j = L[v]; j <= R[v]; ++j) {
                int x = rev[j];
                if (x <= n) add(x); // Check boundary before accessing rev[j]
            }
        }

        for (const auto& [idx, k] : queries[u]) {
            ans[idx] = sum[k];
        }

        if (!iss) {
            for (int i = L[u]; i <= R[u]; ++i) {
                del(rev[i]);
            }
        }
    };

    DfsSec(1, true);

    for (int i = 1; i <= m; ++i) {
        std::cout << ans[i] << '\n';
    }

    return 0;
}