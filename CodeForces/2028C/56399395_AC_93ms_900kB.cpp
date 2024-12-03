#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		long long v;
		cin >> v;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		vector<long long> sums(n + 1);
		for (int i = 0; i < n; i++) sums[i + 1] = sums[i] + a[i];

		auto query = [&](int i, int j) { // [i, j)
			return sums[j] - sums[i];
		};

		auto compute_pfx = [&]() -> vector<int> {
			vector<int> pfx(n + 1, 0);
			int end = 0;
			long long sum = 0;
			for (int start = 0; start < n; start++) {
				while (end < n && sum < v) {
					sum += a[end++];
					pfx[end] = max(pfx[end], pfx[end - 1]);
				}
				if (sum >= v) pfx[end] = 1 + pfx[start];
				sum -= a[start];
			}
			for (int i = 1; i <= n; i++) pfx[i] = max(pfx[i], pfx[i - 1]);
			return pfx;
		};

		auto pfx = compute_pfx();
		reverse(a.begin(), a.end());
		auto sfx = compute_pfx();
		reverse(a.begin(), a.end());
		reverse(sfx.begin(), sfx.end());

		if (pfx[n] < m) {
			cout << "-1\n";
			continue;
		}

		int end = 0;
		long long ans = 0;
		for (int start = 0; start < n; start++) {
			while (end < n && pfx[start] + sfx[end + 1] >= m) ++end;
			if (pfx[start] + sfx[end] >= m)
				ans = max(ans, query(start, end));
		}
		cout << ans << "\n";
	}
}