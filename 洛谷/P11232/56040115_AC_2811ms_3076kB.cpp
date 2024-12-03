#include <bits/stdc++.h>
using namespace std;
int a[100005], d[100005], v[100005], p[100005];
int del[100005];

struct node {
	int ql, qr;
	friend bool operator<(node l, node r) {
		if (l.ql != r.ql)
			return l.ql < r.ql;
		return l.qr > r.qr;
	}
} s[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, L, V;
		cin >> n >> m >> L >> V;
		for (int i = 1; i <= n; ++i)
			cin >> d[i] >> v[i] >> a[i];
		for (int i = 1; i <= m; ++i)
			cin >> p[i];
		int tot = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i] <= 0 && v[i] <= V)
				continue;
			if (a[i] > 0) {
				int wei = V * V - v[i] * v[i];
				wei /= (2 * a[i]);
				wei += d[i];
				if (v[i] > V)
					wei = d[i] - 1;
				int l = 1, r = m, ans = 0;
				while (l <= r) {
					int mid = (l + r) / 2;
					if (p[mid] > wei) {
						r = mid - 1;
						ans = mid;
					} else
						l = mid + 1;
				}
				if (!ans)
					continue;
				s[++tot].ql = ans, s[tot].qr = m;
			} else {
				int l = 1, r = m, pos = 0;
				while (l <= r) {
					int mid = (l + r) / 2;
					if (p[mid] >= d[i]) {
						r = mid - 1;
						pos = mid;
					} else
						l = mid + 1;
				}
				if (!pos)
					continue;
				l = pos, r = m;
				int ans = 0;
				while (l <= r) {
					int mid = (l + r) / 2;
					double su = sqrt(v[i] * v[i] * 1.0 + 2.0 * a[i] * (p[mid] - d[i]));
					if (su > V) {
						l = mid + 1;
						ans = mid;
					} else
						r = mid - 1;
				}
				if (ans < pos)
					continue;
				s[++tot].ql = pos, s[tot].qr = ans;
			}
		}
		sort(s + 1, s + tot + 1);
		int mr = 1000000000;
		for (int i = tot; i >= 1; --i) {
			if (mr <= s[i].qr)
				del[i] = 1;
			mr = min(mr, s[i].qr);
		}
		int ans = 0, fu = 0;
		for (int i = 1; i <= tot; ++i) {
			//	cout << s[i].ql << " " << s[i].qr << " " << del[i] << endl;
			if (del[i]) {
				del[i] = 0;
				continue;
			}
			if (fu < s[i].ql) {
				ans++;
				fu = s[i].qr;
			}
		}
		cout << tot << " " << m - ans << "\n";
	}
}