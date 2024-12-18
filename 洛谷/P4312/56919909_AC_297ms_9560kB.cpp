#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 3e4 + 10;
constexpr int Q = 3e5 + 10;

int n, q;
int a[N], fa[N], sz[N], dep[N], son[N], top[N], id[N], rid[N], tot;
int f[N], sum[N << 2], l[N << 2], r[N << 2];
char op[Q][10];
int x[Q], y[Q];
std::vector<int> e[N];

// 并查集
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return false;
    fa[fx] = fy;
    return true;
}

// 树链剖分 - dfs1
void dfs1(int u, int p) {
    sz[u] = 1;
    dep[u] = dep[p] + 1;
    f[u] = p;
    for (int v : e[u]) {
        if (v == p) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) son[u] = v;
    }
}

// 树链剖分 - dfs2
void dfs2(int u, int tp) {
    top[u] = tp;
    id[u] = ++tot;
    rid[tot] = u;
    if (son[u]) dfs2(son[u], tp);
    for (int v : e[u]) {
        if (v == son[u] || v == f[u]) continue;
        dfs2(v, v);
    }
}

// 线段树 - 建树
void build(int o, int L, int R) {
    l[o] = L, r[o] = R;
    if (L == R) {
        sum[o] = a[rid[L]];
        return;
    }
    int mid = (L + R) / 2;
    build(o << 1, L, mid);
    build(o << 1 | 1, mid + 1, R);
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
}

// 线段树 - 单点更新
void update(int o, int idx, int val) {
    if (l[o] == r[o]) {
        sum[o] = val;
        return;
    }
    int mid = (l[o] + r[o]) / 2;
    if (idx <= mid) update(o << 1, idx, val);
    else update(o << 1 | 1, idx, val);
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
}

// 线段树 - 区间查询
int query(int o, int L, int R) {
    if (L <= l[o] && r[o] <= R) return sum[o];
    int mid = (l[o] + r[o]) / 2, res = 0;
    if (L <= mid) res += query(o << 1, L, R);
    if (mid < R) res += query(o << 1 | 1, L, R);
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    std::cin >> q;
    for (int i = 1; i <= q; i++) std::cin >> op[i] >> x[i] >> y[i];

    // 建树
    for (int i = 1; i <= q; i++) {
        if (op[i][0] == 'b' && merge(x[i], y[i])) {
            e[x[i]].push_back(y[i]);
            e[y[i]].push_back(x[i]);
        }
    }

    // 树链剖分
    for (int i = 1; i <= n; i++) {
        if (fa[i] == i) {
            dfs1(i, 0);
            dfs2(i, i);
        }
    }
    build(1, 1, n);

    // 并查集恢复
    for (int i = 1; i <= n; i++) fa[i] = i;

    // 处理操作
    for (int i = 1; i <= q; i++) {
        if (op[i][0] == 'b') {
            std::cout << (merge(x[i], y[i]) ? "yes\n" : "no\n");
        } else if (op[i][0] == 'p') {
            update(1, id[x[i]], y[i]);
        } else {
            if (find(x[i]) != find(y[i])) {
                std::cout << "impossible\n";
            } else {
                int res = 0, u = x[i], v = y[i];
                while (top[u] != top[v]) {
                    if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
                    res += query(1, id[top[u]], id[u]);
                    u = f[top[u]];
                }
                if (dep[u] > dep[v]) std::swap(u, v);
                res += query(1, id[u], id[v]);
                std::cout << res << "\n";
            }
        }
    }

    return 0;
}
