#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

constexpr int inf = 1E9;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector a(2, std::vector<int>(n));
    i64 ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }
    int mx = -inf;
    for (int i = 0; i < n; i++) {
        ans += std::max(a[0][i], a[1][i]);
        mx = std::max(mx, std::min(a[0][i], a[1][i]));
    }
    ans += mx;
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}