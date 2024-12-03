#include <bits/stdc++.h>
using i64 = long long;

constexpr int N = 105;

i64 n, m, v[N][N], a[N], b[N], c, g;

bool flag = true;

signed main() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> v[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		b[i] = v[1][i];
	}

	for (int i = 1; i <= n; i++) {
		a[i] = v[i][1] - b[1];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			c = abs(a[i] + b[j] - v[i][j]), g = std::__gcd(g, c);
		}
	}

	if (!g)  {
		g = 1000000007;
	}
	for (int i = 1; i <= n && flag; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i][j] >= g) {
				flag = false;
				break;
			}
		}
	}
	if (!flag) {
		std::cout << "NO\n";
		return 0;
	}
	std::cout << "YES\n" << g << std::endl;
	for (int i = 1; i <= n; ++i)
		std::cout << (a[i] + g) % g << ' ';
	std::cout << std::endl;
	for (int i = 1; i <= m; ++i)
		std::cout << (b[i] + g) % g << ' ';
	std::cout << std::endl;
	return 0;
}