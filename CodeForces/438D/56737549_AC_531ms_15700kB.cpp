#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 4e5 + 10;

i64 a[N], sum[N], maxx[N], l[N], r[N];

void build (int o, int ll, int rr) {
    l[o] = ll, r[o] = rr;
    if (ll == rr) {
        sum[o] = maxx[o] = a[ll];
        return;
    }
    int mid = ll + rr >> 1;
    build (o << 1, ll, mid);
    build (o << 1 | 1, mid + 1, rr);
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
    maxx[o] = std::max(maxx[o << 1], maxx[o << 1 | 1]);
    return;
}

void ModifyMod (int o, int ll, int rr, int p) {
    if (maxx[o] < p) {
        return;
    }
    if (l[o] == r[o]) {
        sum[o] %= p;
        maxx[o] = sum[o];
        return;
    }
    if (r[o << 1] >= ll) ModifyMod (o << 1, ll, rr, p);
    if (l[o << 1 | 1] <= rr) ModifyMod (o << 1 | 1, ll, rr, p);
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
    maxx[o] = std::max(maxx[o << 1], maxx[o << 1 | 1]);   
}

void Modify (int o, int x, int k) {
    if (l[o] == r[o]) {
        sum[o] = maxx[o] = k;
        return;
    }
    if (x <= r[o << 1]) Modify(o << 1, x, k);
    else Modify (o << 1 | 1, x, k);
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
    maxx[o] = std::max(maxx[o << 1], maxx[o << 1 | 1]);
}

i64 query (int o, int ll, int rr) {
    if (ll <= l[o] && r[o] <= rr) return sum[o];
    i64 ans = 0;
    if (ll <= r[o << 1]) ans += query(o << 1, ll, rr);
    if (l[o << 1 | 1] <= rr) ans += query(o << 1 | 1, ll, rr);
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    build (1, 1, n);
    while (q--) {
        int op, l, r, k, x;
        std::cin >> op;
        if (op == 1) {
            std::cin >> l >> r;
            std::cout << query (1, l, r) << std::endl;
        } else if (op == 2) {
            std::cin >> l >> r >> x;
            ModifyMod(1, l, r, x);
        } else {
            std::cin >> k >> x;
            Modify (1, k, x);
        }
    }
    return 0;
}
