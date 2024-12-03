#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, ans;
int a[105], b[105];
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++)
                if (a[i] + b[j] <= k)
                    ans++;
        cout << ans << '\n';
    }
    return 0;
}