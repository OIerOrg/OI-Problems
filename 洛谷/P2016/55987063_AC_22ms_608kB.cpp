#include <bits/stdc++.h>
using namespace std;
const int N = 1510;
int n, LD;
int Arr[N];
int dp[N][2];
bool Fa[N];
vector<int> Edge[N];
void dfs(int i) {
	// dp[i][0] 他不选
	dp[i][1] = 1;
	for (int j = 0; j < Edge[i].size(); j++) {
		int v = Edge[i][j];
		dfs(v);
		dp[i][0] += dp[v][1];
		dp[i][1] += min(dp[v][0], dp[v][1]);
	}
	return;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, x;
		cin >> a >> x;
		while (x--) {
			int y;
			cin >> y;
			Fa[y] = true;
			Edge[a].push_back(y);
		}
	}
	for (int i = 0; i < n; i++)
		if (!Fa[i]) {
			LD = i;
			break;
		}
	dfs(LD);
	cout << min(dp[LD][0], dp[LD][1]);
}