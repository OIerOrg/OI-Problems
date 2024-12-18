#include<bits/stdc++.h>
using namespace std;
#define DISABLE_MMAP
const int N = 32; bool M[N][N]; int n, m, t;
bool vis[N][N][N][N];
int sx, sy, tx, ty, ex, ey;
struct node {
	int x, y, ex, ey, step;
	node(int a, int b, int c, int d, int e) {
		x = a, y = b, ex = c, ey = d, step = e;
	}
	node() {
		
	}
} q[N * N * N * N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int bfs() {
	int hh = 0, tt = -1;
	q[++tt] = node(sx, sy, ex, ey, 0);
	vis[sx][sy][ex][ey] = 1;
	while(hh <= tt) {
		node f = q[hh++];
		if(f.x == tx && f.y == ty) return f.step;
		for(int i = 0; i < 4; i++) {
			int nex = f.ex + dx[i];
			int ney = f.ey + dy[i];
			if(nex < 1 || nex > n || ney < 1 || ney > m) continue;
			if(!M[nex][ney]) continue;
			int nx = f.x, ny = f.y;
			if(nx == nex && ny == ney) nx = f.ex, ny = f.ey;
			if(vis[nx][ny][nex][ney]) continue;
			vis[nx][ny][nex][ney] = 1;
			q[++tt] = node(nx, ny, nex, ney, f.step + 1);
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> t;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> M[i][j];
		}
	}
	while(t--) {
		memset(vis, 0, sizeof vis);
		cin >> ex >> ey >> sx >> sy >> tx >> ty;
		cout << bfs() << '\n';
	}
	return 0;
}