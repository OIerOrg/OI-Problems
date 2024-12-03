#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 10;
int n, ans = 1e9;
int arr[N];
int main() {
#ifdef kimi
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i <= n; i++) {
			bool change = false;
			for (int i = 1; i < n; i++) if (arr[i] == arr[i + 1] + 1) swap (arr[i], arr[i + 1]), change = true;
			if (change) continue;
			break;
		}
		int ok = true;
		for (int i = 1; i <= n; i++) {
			if (i == arr[i]);
			else ok = false;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}