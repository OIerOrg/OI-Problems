#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, cnt;
char c;
int x;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    while (n--) {
        cin >> c >> x;
        if (c == 'B') {
            if (cnt < x) cout << "YES\n";
            else cout << "NO\n";
            cnt = max (cnt - x, 0ll);
        } else {
            cnt += x;
        }
    }
	return 0;
}