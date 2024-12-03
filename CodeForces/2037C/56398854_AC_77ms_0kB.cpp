#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve () {
    int n; cin >> n;
    if (n < 5) return puts("-1"), void();
    for (int i = 6; i <= n; i += 2) cout << i << ' ';
    cout <<"2 4 5 1 3 ";
    for (int i = 7; i <= n; i += 2) cout << i << ' ';
    cout << '\n';
}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
       solve();
    }
	return 0;
}