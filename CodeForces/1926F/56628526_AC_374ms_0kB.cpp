#include <bits/stdc++.h>

using i64 = long long;

int Ans;

std::array <std::string, 7> s;
std::array <std::array<bool, 7>, 7> f;

void dfs (int x, int y, int cnt) {
    if (cnt >= Ans) return;
    if (x == 7) return Ans = cnt, void();
    if (x > 1 && y > 2 && f[x - 2][y - 3] && f[x - 2][y - 1] && f[x - 1][y - 2] && f[x][y - 3] && f[x][y - 1]) return;
    if (y == 7) return dfs (x + 1, 0, cnt);
    f[x][y] = s[x][y] == 'B';
    dfs (x, y + 1, cnt);
    if (f[x][y] && std::abs(x - 3) + std::abs(y - 3) <= 3) {
        f[x][y] = 0;
        dfs(x, y + 1, cnt + 1);
        f[x][y] = 1;
    }
}
int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        Ans = 8;
    	for (int i = 0; i < 7; i++) {
    	    std::cin >> s[i];
    	}
        dfs (0, 0, 0);
        std::cout << Ans << std::endl;
    }
    return 0;
}
