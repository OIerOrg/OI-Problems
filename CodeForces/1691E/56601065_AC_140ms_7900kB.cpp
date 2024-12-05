#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 10;
ll T, n, ans, l0[N], r0[N], x0[N], l1[N], r1[N], x1[N], ct0, ct1, fa[N];
struct P {
    bool col;
    ll l, r;
    bool operator<(const P& b) { return r < b.r; }
} a[N];
ll getfa(ll x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
void hb(ll x, ll y) {
    x = getfa(x), y = getfa(y);
    if (x ^ y) fa[x] = y, ans--;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i].col >> a[i].l >> a[i].r;
        sort(a + 1, a + n + 1);
        ct0 = ct1 = 0, ans = n;
        for (int i = 1; i <= n; i++) fa[i] = i;
        for (int i = 1, j; i <= n; i++) {
            if (a[i].col) {
                j = ct0;
                while (j && ((l0[j] <= a[i].l && a[i].l <= r0[j]) || (a[i].l <= l0[j] && a[i].r >= l0[j]))) hb(x0[j], i), j--;
                if (ct0) l0[++j] = l0[ct0], r0[j] = r0[ct0], x0[j] = x0[ct0], ct0 = j;
                l1[++ct1] = a[i].l, r1[ct1] = a[i].r, x1[ct1] = i;
            } else {
                j = ct1;
                while (j && ((l1[j] <= a[i].l && a[i].l <= r1[j]) || (a[i].l <= l1[j] && a[i].r >= l1[j]))) hb(x1[j], i), j--;
                if (ct1) l1[++j] = l1[ct1], r1[j] = r1[ct1], x1[j] = x1[ct1], ct1 = j;
                l0[++ct0] = a[i].l, r0[ct0] = a[i].r, x0[ct0] = i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}