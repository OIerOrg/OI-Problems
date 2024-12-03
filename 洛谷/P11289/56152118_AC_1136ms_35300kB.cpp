#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
int n, m;
struct File_ { int s, t, id; } a[N];
bool operator < (File_ a, File_ b) {
    return a.t < b.t;
}
struct Print {
    LL now, id;
    bool operator < (const Print &x) const {
        return now > x.now || (now == x.now && id > x.id);
    }
};
priority_queue <Print> q, Q;
// q 中存 0 Q 中存非 0
vector <int> ans[N];
signed main () {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].s >> a[i].t, a[i].id = i;
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= m; ++i)
        q.push ({0, i});
    for (int i = 1; i <= n; ++i) {
        if (!Q.empty ()) {
            vector <int> v;
            while (!Q.empty ()) {
                LL x = Q.top ().now;
                if (x > a[i].t) break;
                v.push_back (Q.top ().id), Q.pop ();
            }
            for (auto j : v) q.push ({0, j});
        }
        int id;
        if (!q.empty ()) {
            id = q.top ().id; q.pop ();
            Q.push ({a[i].t + a[i].s, id});
        }
        else {
            id = Q.top ().id;
            Q.push ({Q.top ().now + a[i].s, id});
            Q.pop ();
        }
        ans[id].push_back (a[i].id);
    }
    for (int i = 1; i <= m; ++i) {
        cout << ans[i].size () << ' ';
        sort (ans[i].begin (), ans[i].end ());
        for (auto &j : ans[i]) cout << j << ' ';
        cout << '\n';
    }
    return 0;
}