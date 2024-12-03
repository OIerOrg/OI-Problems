#include <bits/stdc++.h>
std::vector<int> v[200005];
int fa[200005][20];
int dep[200005];
int d[200005];
void dfs(int p) {
    d[p] = dep[p] = dep[fa[p][0]] + 1;
    for (int i = 1; i < 20; ++i)
        fa[p][i] = fa[fa[p][i - 1]][i - 1];
    for (const int& i : v[p])
        if (i != fa[p][0])
            fa[i][0] = p, dfs(i),
            d[p] = std::max(d[p], d[i]);
}
int st[200005][20];
void dfs2(int p) {
    for (int i = 1; i < 20; ++i)
        st[p][i] = std::max(st[p][i - 1], st[fa[p][i - 1]][i - 1]);
    for (const int& i : v[p])
        if (i != fa[p][0]) dfs2(i);
}
int T, n, m, ans;
int main() {
    for (int i = 0; i < 20; ++i)
        st[0][i] = st[1][i] = 0xc0c0c0c0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) v[i].clear();
        for (int i = 1, x, y; i < n; ++i)
            scanf("%d%d", &x, &y),
                v[x].push_back(y), v[y].push_back(x);
        dfs(1);
        for (int i = 1; i <= n; ++i) {
            static int pre[200005], suf[200005];
            pre[0] = suf[v[i].size() - 1] = dep[i];
            for (int j = 0; j + 1 < v[i].size(); ++j)
                pre[j + 1] = std::max(pre[j], v[i][j] == fa[i][0] ? 0 : d[v[i][j]]);
            for (int j = v[i].size() - 1; j; --j)
                suf[j - 1] = std::max(suf[j], v[i][j] == fa[i][0] ? 0 : d[v[i][j]]);
            for (int j = 0; j < v[i].size(); ++j)
                if (v[i][j] != fa[i][0]) st[v[i][j]][0] = std::max(pre[j], suf[j]) - (dep[i] << 1);
        }
        dfs2(1);
        scanf("%d", &m);
        for (int x, y, z; m--;) {
            scanf("%d%d", &x, &y);
            z = x;
            ans = 0xc0c0c0c0;
            for (int i = 19; ~i; --i)
                if (y >> i & 1) ans = std::max(ans, st[x][i]), x = fa[x][i];
            ans = std::max(ans + dep[z], d[z] - dep[z]);
            printf("%d ", ans);
        }
        putchar(10);
    }
    return 0;
}