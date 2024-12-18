#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 N = 1e5 + 10, M = N << 1;

i64 n, q;
i64 tot, head[N], nxt[M], to[M], weight[N];
i64 son[N], top[N], id[N], cnt, parent[N], depth[N], tmpWeight[N], size[N];

struct SegmentTreeNode {
    i64 l, r, dist;
} segTree[N << 2];

void addEdge(i64 u, i64 v) {
    nxt[++tot] = head[u], head[u] = tot, to[tot] = v;
}

void dfs1(i64 u, i64 p, i64 d) {
    parent[u] = p, depth[u] = d, size[u] = 1;
    for (i64 i = head[u]; ~i; i = nxt[i]) {
        i64 v = to[i];
        if (v == p) continue;
        dfs1(v, u, d + 1);
        size[u] += size[v];
        if (size[son[u]] < size[v]) son[u] = v;
    }
}

void dfs2(i64 u, i64 t) {
    id[u] = ++cnt, tmpWeight[cnt] = weight[u], top[u] = t;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (i64 i = head[u]; ~i; i = nxt[i]) {
        i64 v = to[i];
        if (v == parent[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

void pushup(i64 u) {
    segTree[u].dist = abs(segTree[u << 1].dist) + abs(segTree[u << 1 | 1].dist);
}

void build(i64 u, i64 l, i64 r) {
    segTree[u] = {l, r, abs(tmpWeight[r])};
    if (l == r) return;
    i64 mid = (l + r) / 2;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void update(i64 u, i64 idx, i64 val) {
    if (segTree[u].l == segTree[u].r) {
        segTree[u].dist = val;
        return;
    }
    i64 mid = (segTree[u].l + segTree[u].r) / 2;
    if (idx <= mid) update(u << 1, idx, val);
    else update(u << 1 | 1, idx, val);
    pushup(u);
}

i64 query(i64 u, i64 l, i64 r) {
    if (l <= segTree[u].l && r >= segTree[u].r) return segTree[u].dist;
    i64 mid = (segTree[u].l + segTree[u].r) / 2, res = 0;
    if (l <= mid) res += query(u << 1, l, r);
    if (r > mid) res += query(u << 1 | 1, l, r);
    return res;
}

void modifyPoint(i64 u, i64 val) {
    update(1, id[u], abs(val));
}

i64 queryPath(i64 u, i64 v) {
    i64 res = -query(1, id[u], id[u]) - query(1, id[v], id[v]);
    while (top[u] != top[v]) {
        if (depth[top[u]] < depth[top[v]]) std::swap(u, v);
        res += 2 * query(1, id[top[u]], id[u]);
        u = parent[top[u]];
    }
    if (depth[u] < depth[v]) std::swap(u, v);
    res += 2 * query(1, id[v], id[u]);
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> q;
    std::memset(head, -1, sizeof head);

    for (i64 i = 1; i <= n; i++) std::cin >> weight[i];
    for (i64 i = 1; i < n; i++) {
        i64 u, v;
        std::cin >> u >> v;
        addEdge(u, v), addEdge(v, u);
    }

    dfs1(1, -1, 1);
    dfs2(1, 1);
    build(1, 1, n);

    while (q--) {
        i64 t, u, v;
        std::cin >> t >> u >> v;
        if (t == 1) modifyPoint(u, v);
        else std::cout << queryPath(u, v) << "\n";
    }

    return 0;
}
