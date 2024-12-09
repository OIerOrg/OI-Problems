#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[65], b, mi[25];
int q;
typedef pair<int, int> pii;
pii f[65][1025];
const int mod = 998244353;
pii dfs(int k, int sta, int p, int q) {
    if (k == -1) return { __builtin_popcount(sta) <= b, 0 };
    if (!p && !q && f[k][sta].first != -1) return f[k][sta];
    int y = q ? a[k] : 9;
    pii res = { 0, 0 };
    for (int i = 0; i <= y; i++) {
        pii nxt = dfs(k - 1, (p && !i) ? sta : (sta | (1 << i)), p && !i, q && (i == y));
        res = (pii) { (res.first + nxt.first) % mod, (nxt.first * mi[k] % mod * i % mod + nxt.second + res.second) % mod };
    }
    if (!p && !q) f[k][sta] = res;
    return res;
}
int solve(int x) {
    for (int i = 0; i <= 20; i++) a[i] = 0;
    int tot = 0;
    while (x) {
        a[tot++] = x % 10;
        x /= 10;
    }
    memset(f, -1, sizeof(f));
    return dfs(tot - 1, 0, 1, 1).second;
}
signed main() {
    mi[0] = 1;
    for (int i = 1; i <= 20; i++) mi[i] = mi[i - 1] * 10 % mod;
    q = 1;
    while (q--) {
        int l, r;
        scanf("%lld%lld%lld", &l, &r, &b);
        printf("%lld\n", (solve(r) - solve(l - 1) + mod) % mod);
    }
    return 0;
}