#include <bits/stdc++.h>
#define maxn 500010
#define lowbit(x) (x & (-x))
typedef long long ll;
using namespace std;
ll n, m;
ll fa[maxn], k, l, r;
ll a[maxn], tree[maxn];
int cnt;
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void add(int x, ll d) {
    while (x <= n) {
        tree[x] += d;
        x += lowbit(x);
    }
}
ll query(int x) {
    ll sum = 0;
    while (x) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}
int main() {
    while (scanf("%lld", &n) != EOF) {
        cnt++;
        for (int i = 1; i <= n * 4; ++i)
            tree[i] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            add(i, a[i]);
            fa[i] = i;
        }
        fa[n + 1] = n + 1;
        scanf("%lld", &m);
        while (m--) {
            scanf("%lld%lld%lld", &k, &l, &r);
            if (l > r)
                swap(l, r);
            if (k == 0) {
                for (int i = l; i <= r;) {
                    add(i, (ll)sqrt(a[i]) - a[i]);
                    a[i] = (ll)sqrt(a[i]);
                    if (a[i] <= 1)
                        fa[i] = i + 1;
                    if (i == find(i))
                        i++;
                    else
                        i = fa[i];
                }
            } else
                printf("%lld\n", query(r) - query(l - 1));
        }
        printf("\n");
    }
    return 0;
}