#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	size_t T;
	cin >> T;

	while (T--) {
		size_t n, m;
		cin >> n >> m;
		vector<map<ui, vector<size_t>>> mp(n);
		while (m--) {
			size_t x, y;
			ui z;
			cin >> x >> y >> z;
			--x;
			--y;
			mp[x][z].push_back(y);
			mp[y][z].push_back(x);
		}

		size_t s, t;
		cin >> s >> t;
		--s;
		--t;
		deque<pair<size_t, ui>> q({{s, ~0}});
		vector<map<ui, ui>> dis(n);
		dis[s][~0] = 0;

		while (!q.empty()) {
			size_t p = q.front().first;
			ui c = q.front().second;
			q.pop_front();
			ui d = dis[p][c];
			if (c != ~0) {
				if (!dis[p].count(~0) || dis[p][~0] > d + 1) {
					dis[p][~0] = d + 1;
					q.emplace_back(p, ~0);
				}
				for (size_t i : mp[p][c]) {
					if (!dis[i].count(c) || dis[i][c] > d) {
						dis[i][c] = d;
						q.emplace_front(i, c);
					}
				}
			} else {
				for (auto& [value, neighbors] : mp[p]) {
					if (!dis[p].count(value) || d < dis[p][value]) {
						dis[p][value] = d;
						q.emplace_front(p, value);
					}
				}
			}
		}
		cout << (dis[t].count(~0) ? dis[t][~0] : -1) << '\n';
	}

	return 0;
}
