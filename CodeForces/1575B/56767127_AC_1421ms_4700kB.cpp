#include <bits/stdc++.h>
#define db double
#define mp make_pair
#define fi first
#define se second
#define PDD pair<double, double>
#define pi 3.14159265358979
using namespace std;
const int M = 1e5 + 7;
const db Eps = 1e-6;
int n, k;
PDD a[M + M + 1];
db x[M], y[M], l, r = 2e5, mid;
db dis(int i) {
    return sqrt(x[i] * x[i] + y[i] * y[i]);
}
bool cmp(PDD a, PDD b) {
    if (a.fi != b.fi) return a.fi < b.fi;
    return a.se > b.se;
}
int check(db r) {
    int ans = 0, s = 0, t = 0;
    db af, bt, d = r + r;
    for (int i = 1; i <= n; i++)
        if (dis(i) <= d) {
            af = atan2(x[i], y[i]), bt = acos(dis(i) / d);
            a[++t] = mp(af - bt < -pi ? af - bt + 3 * pi : af - bt + pi, 1);
            a[++t] = mp(af + bt > pi ? af + bt - pi : af + bt + pi, -1);
            s += (a[t].fi < a[t - 1].fi);
        }
    sort(a + 1, a + t + 1, cmp);
    for (int i = 1; i <= t; i++)
        s = max(s, 0) + a[i].se, ans = max(s, ans);
    return ans >= k;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &x[i], &y[i]);
    while (r > l + Eps) {
        mid = (l + r) * 0.5;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    printf("%.7lf", l);
    return 0;
}