#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve () {
    map <int, int> m;
    int n;
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        m[x]++;
    } n -= 2;
    for (int i = 1; i * i <= n; i++) {
        if (n % i) continue;
        int j = n / i;
        if (i == j && m[i] >= 2) {
            cout << i << ' ' << j << '\n';
            return;
        } else if (m[i] && m[j]) {
            cout << i << ' ' << j << '\n';
            return;
        }
    }
}
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
       solve();
    }
	return 0;
}