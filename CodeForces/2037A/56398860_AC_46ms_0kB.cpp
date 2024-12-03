#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        map <int, bool> m;
        int n, ans = 0; cin >> n;
        while (n--) {
            int x;
            cin >> x;
            if (m[x]) ans++, m[x] = 0;
            else m[x] = 1;
        }
        cout << ans << '\n';
    }
	return 0;
}