#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 2e5 + 5, inf = 0x3f3f3f3f;
vector<int> e[N];
int n, m, k;
int vis[N], pos;
void dfs(int u, int tim) {
    vis[u] = tim;
    for (auto v : e[u]) {
        if (!vis[v]) {
            dfs(v, tim + 1);
            break;
        }
        if (vis[u] >= vis[v] + k) {
            cout << vis[u] - vis[v] + 1 << endl;
            cout << u << " ";
            pos = v;
            return;
        }
    }
    if (pos != -1) cout << u << " ";
    if (pos == u) pos = -1;
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 1);
}