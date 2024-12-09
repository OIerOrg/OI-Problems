#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 500005;
int n, m, s, t, ds, dt, tot;
int f[N];

int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

struct node {
    int x, y, z;
} a[N], ans[N];

bool Q(node x, node y) {
    return x.z < y.z;
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
        std::cin >> a[i].x >> a[i].y;
    std::cin >> s >> t >> ds >> dt;
    for (int i = 0; i < m; i++)
        a[i].z = (a[i].x == s || a[i].x == t) + (a[i].y == s || a[i].y == t);
    std::random_shuffle(a, a + m);
    std::sort(a, a + m, Q);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 0; i < m; i++) {
        int x = find(a[i].x), y = find(a[i].y);
        bool is = (a[i].x == s || a[i].y == s); 
        bool it = (a[i].x == t || a[i].y == t);
        if (x == y || ds == 0 && is || dt == 0 && it)
            continue;
        f[x] = y;
        ans[tot++] = a[i];
        ds -= is, dt -= it;
    }
    if (tot < n - 1) {
        std::cout << "No\n";
        return 0;
    }
    std::cout << "Yes\n";
    for (int i = 0; i < tot; i++)
        std::cout << ans[i].x << ' ' << ans[i].y << '\n';
}
