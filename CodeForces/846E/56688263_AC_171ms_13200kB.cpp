// 18 43

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using pii = std::pair <int, int>;
constexpr int N = 1e5 + 10;

std::vector<pii> edge[N];
i64 a[N], b[N];
long double f[N];

void dfs (int x) {
    for (auto [i, j] : edge[x]) {
        dfs (i);
        if (f[i] >= 0) {
            f[x] += f[i];
        } else {
            f[x] += j * f[i];
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        f[i] = a[i] - b[i];
    }
    for (int i = 2; i <= n; i++) {
        int x, y;
        std::cin >> x >> y;
        edge[x].push_back({i, y});
    }
    dfs (1);
    std::cout << (f[1] >= 0 ? "YES": "NO") << std::endl;
    return 0;
}