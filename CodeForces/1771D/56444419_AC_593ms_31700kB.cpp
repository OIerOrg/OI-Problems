#include <bits/stdc++.h>

constexpr int N = 2000 + 10;
int n, dp[N][N], ans;
int fa[N][N];
std::string s;
std::vector<int> E[N];

void dfs(int x, int parent, int root) {
	fa[root][x] = parent;
	for (int y : E[x]) {
		if (y != parent) {
			dfs(y, x, root);
		}
	}
}

int calc(int x, int y) {
	if (x == y) return 1;
	if (x == fa[1][y] || y == fa[1][x]) return 1 + (s[x] == s[y]);
	if (dp[x][y]) return dp[x][y];
	
	int res = std::max({
		calc(x, fa[x][y]),
		calc(y, fa[y][x]),
		calc(fa[x][y], fa[y][x]) + (s[x] == s[y] ? 2 : 0)
	});
	return dp[x][y] = res;
}

void solve() {
	std::cin >> n;
	std::cin >> s;
	s = " " + s;
	
	memset(dp, 0, sizeof(dp));
	memset(fa, 0, sizeof(fa));
	for (int i = 1; i <= n; ++i) {
		E[i].clear();
	}
	
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	for (int i = 1; i <= n; ++i) {
		dfs(i, 0, i);
	}
	
	ans = 0;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			ans = std::max(ans, calc(i, j));
		}
	}
	
	printf("%d\n", ans);
}

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}