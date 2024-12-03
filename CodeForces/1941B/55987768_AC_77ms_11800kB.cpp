#include <bits/stdc++.h>
const int N = 3000000;
using namespace std;
int t, n, a[N];
bool flag;
signed main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        flag = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n - 2; i++) {
            if (a[i] < 0) {
                puts("NO");
                flag = 1;
                break;
            }
            a[i + 2] -= a[i];
            a[i + 1] -= a[i] * 2;
            a[i] = 0;
        }
        if (flag) continue;
        if (a[n - 1] == 0 && a[n] == 0)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}