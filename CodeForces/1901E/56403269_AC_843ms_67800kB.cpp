#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 10;

int t, n; ll a[MAXN], dp[MAXN], ans;

vector<int> g[MAXN];

void dfs(int u, int fa) {
	ll x; vector<ll> d; dp[u] = a[u], ans = max(ans, dp[u]);
	for (int v : g[u]) {
		if (v == fa) continue; dfs(v, u), d.push_back(dp[v]);
		ans = max(ans, a[u] + dp[v]), dp[u] = max(dp[u], dp[v]);
	}
	sort(d.begin(), d.end(), greater<ll>());
	if (d.size() >= 2) {
		x = d[0] + d[1], ans = max(ans, x);
		for (int i = 2; i < d.size() && d[i] > 0; i++) x += d[i];
		dp[u] = max(dp[u], a[u] + x);
	}
	if (d.size() >= 3) {
		x = d[0] + d[1] + d[2];
		for (int i = 3; i < d.size() && d[i] > 0; i++) x += d[i];
		ans = max(ans, a[u] + x);
	}
}

int main() {
	for (scanf("%d", &t); t--;) {
		scanf("%d", &n), ans = 0;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		for (int i = 1, u, v; i < n; i++) {
			scanf("%d%d", &u, &v);
			g[u].push_back(v), g[v].push_back(u);
		}
		dfs(1, 0), printf("%lld\n", ans);
	}
}