#include <bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n, b, c;
void solve() {
	cin >> n >> b >> c;
	if (b == 0) {
		if (c >= n) {
			cout << n << "\n";
		} else if (c >= n - 2) {
			cout << n - 1 << "\n";
		} else {
			cout << -1 << "\n";
		}
	} else {
		if (c >= n) cout << n << "\n";
		else cout << n - max(0LL, 1 + (n - c - 1) / b) << "\n";
	}
}
signed main() {
	cin >> t;
	while (t--) {
		solve();
	}
}