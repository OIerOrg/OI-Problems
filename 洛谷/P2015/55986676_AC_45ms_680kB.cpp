#include <bits/stdc++.h>
#define pii pair <int, int>
using namespace std;
const int N = 105;
int n, q, x, y, z;
vector <pii> edge[N];
int f[N][N]; // 第 i 个子树， 保留了 j 个树枝的最大值。
void dfs (int x, int fa) {
	if (edge[x].size() == 1) {
		return;
	}
	pii	ls, rs;
	if (edge[x][0].first == fa) ls = edge[x][1], rs = edge[x][2];
	else if (edge[x][1].first == fa) ls = edge[x][0], rs = edge[x][2];
	else if (edge[x][2].first == fa) ls = edge[x][0], rs = edge[x][1];
	dfs (ls.first, x);
	dfs (rs.first, x);
	for (int i = 1; i <= q; i++) {
		f[x][i] = max({f[x][i], f[ls.first][i - 1] + ls.second, f[rs.first][i - 1] + rs.second});
		for (int j = 0; j <= i - 2; j++)
			f[x][i] = max(f[x][i], f[ls.first][j] + ls.second + f[rs.first][i - j - 2] + rs.second);
	}
}
int main() {
	scanf ("%d %d", &n, &q);
	for (int i = 1; i < n; i++) {
		scanf ("%d %d %d", &x, &y, &z);
		edge[x].emplace_back(y, z);
		edge[y].emplace_back(x, z);
	}
	dfs (1, 0);
	printf ("%d", f[1][q]);
}