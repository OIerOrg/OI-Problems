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
        ans = 1e9;
		map <int, int> cnt;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i], cnt[arr[i]]++;
		for (auto i : cnt) {
			ans = min(ans, n - i.second);
		}
		cout << ans << '\n';
	}
	return 0;
}