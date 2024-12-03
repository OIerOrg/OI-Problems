#include<bits/stdc++.h>
#define int long long
#define For(i, a, b) for(int i = (a); i <= (b); i++)
#define Rof(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
const int N = 5e5 + 5;
int n, k, tot = 1, a[N], ch[N * 15][2], mx[N * 15];
void add(int x, int pos) {
	int now = 1;
	Rof(i, 29, 0) {
		int p = (x >> i) & 1;
		if (!ch[now][p]) ch[now][p] = ++tot;
		now = ch[now][p];
		mx[now] = max(mx[now], pos);
	}
}
int query(int x, int mid) {
	int now = 1, pos = 0;
	Rof(i, 29, 0) {
		int p1 = (x >> i) & 1, p2 = (mid >> i) & 1;
		if (p2) pos = max(pos, mx[ch[now][p1]]), now = ch[now][p1 ^ 1];
		else now = ch[now][p1];
	}
	pos = max(pos, mx[now]);
	return pos;
}
int check(int mid) {
	int sum = 0, pos = 0;
	For(i, 1, n) {
		pos = max(pos, query(a[i], mid));
		add(a[i], i);
		sum += pos;
	}
	For(i, 0, tot) mx[i] = ch[i][0] = ch[i][1] = 0;
	tot = 1;
	return sum;
}
void Solve() {
	cin >> n >> k;
	For(i, 1, n) cin >> a[i];
	int l = 0, r = (1 << 30) - 1, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid) >= k) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--) Solve();
	return 0;
}