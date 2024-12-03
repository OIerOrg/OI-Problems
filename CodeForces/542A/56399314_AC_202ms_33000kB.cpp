#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair < LL, int > PLI;
const int SIZE = 3e5 + 5;

int n, m, N;

struct node {
	int l, r, c, idx;
	bool operator < (const node &a) const {
		return l == a.l ? r > a.r : l < a.l;
	}
	LL operator & (const node &a) const {
		if (l <= a.l && r >= a.r) return a.r - a.l;
		if (l >= a.l && r <= a.r) return r - l;
		return std::max(0, std::min(r, a.r) - std::max(l, a.l));
	}
} a[SIZE], b[SIZE], c[SIZE];

namespace GTR {
	const int bufl = 1 << 15;
	char buf[bufl], *s = buf, *t = buf;
	inline int fetch() {
		if (s == t) {
			t = (s = buf) + fread(buf, 1, bufl, stdin);
			if (s == t) return EOF;
		}
		return *s++;
	}
	inline int read() {
		int a = 0, b = 1, c = fetch();
		while (c < 48 || c > 57) b ^= c == '-', c = fetch();
		while (c >= 48 && c <= 57) a = (a << 1) + (a << 3) + c - 48, c = fetch();
		return b ? a : -a;
	}
} using GTR::read;

namespace segmentTree {
	PLI len[SIZE << 2];
#define lson(p) (p << 1)
#define rson(p) (p << 1 | 1)

	void pushUp(int p) {
		PLI ans = len[lson(p)];
		if (len[rson(p)].second > ans.second) ans = len[rson(p)];
		len[p] = ans;
	}

	void build(int p, int l, int r) {
		if (l == r) return len[p] = (PLI) {a[l].idx, 1ll * a[l].r - a[l].l}, void();
		int mid = (l + r) / 2;
		build(lson(p), l, mid), build(rson(p), mid + 1, r);
		pushUp(p);
	}
	PLI query(int p, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) return len[p];
		int mid = (l + r) >> 1;
		PLI ans = (PLI) {
			0, 0
		};
		if (ql <= mid) {
			PLI res = query(lson(p), l, mid, ql, qr);
			if (res.second > ans.second) ans = res;
		}
		if (qr > mid) {
			PLI res = query(rson(p), mid + 1, r, ql, qr);
			if (res.second > ans.second) ans = res;
		}
		return ans;
	}
} using segmentTree::build;
using segmentTree::query;

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) c[i].l = read(), c[i].r = read(), c[i].idx = i;
	for (int i = 1; i <= m; ++i) b[i].l = read(), b[i].r = read(), b[i].c = read();
	std::sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; ++i) a[i] = c[i];
	N = 1;
	for (int i = 2; i <= n; ++i) {
		if (a[i].r > a[N].r) a[++ N] = a[i];
	}
	build(1, 1, N);
	LL ans = -1e18;
	int ansl = 0, ansr = 0;
	for (int i = 1; i <= m; ++ i) {
		int l = 1, r = N, mid;
		while (l < r) {
			mid = (l + r) / 2;
			if (l == mid) break;
			if (a[mid].l < b[i].l) l = mid;
			else r = mid;
		}
		LL res = 1ll * (b[i] & a[l]) * b[i].c;
		if (ans < res) ans = res, ansl = a[l].idx, ansr = i;
		// ans = std::max(ans, 1ll * (b[i] & a[l]) * b[i].c);
		int L = l + 1, R;
		l = 1, r = N, mid;
		while (l < r) {
			mid = (l + r) / 2;
			if (a[mid].r > b[i].r) r = mid;
			else l = mid + 1;
		}
		R = r - 1;
		res = 1ll * (b[i] & a[r]) * b[i].c;
		if (ans < res) ans = res, ansl = a[r].idx, ansr = i;
		if (R >= L) {
			PLI tmp = query(1, 1, N, L, R);
			res = 1ll * tmp.second * b[i].c;
			if (ans < res) ans = res, ansl = tmp.first, ansr = i;
		}
	}
	if (ans <= 0) puts("0");
	else printf("%lld\n%d %d\n", ans, ansl, ansr);
	return 0;
}