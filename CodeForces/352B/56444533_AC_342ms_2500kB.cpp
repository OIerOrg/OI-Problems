#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 100010;
int a[N], T[N], d[N];
bool ok[N];
int maxn, n;
signed main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    maxn = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (T[a[i]]) {
            if (!d[a[i]]) {
                d[a[i]] = (i - T[a[i]]);
            } else if (i - T[a[i]]!= d[a[i]]) {
                ok[a[i]] = 1;
            }
        }
        T[a[i]] = i;
    }
    int cnt = 0;
    for (int i = 1; i <= maxn; i++) {
        if (ok[i] == 0 && T[i] != 0) {
            ++cnt;
        }
    }
    cout << cnt << '\n';
    for (int i = 1; i <= maxn; i++) {
        if (ok[i] == 0 && T[i] != 0) {
            cout << i << " " << d[i] << '\n';
        }
    }
    return 0;
}