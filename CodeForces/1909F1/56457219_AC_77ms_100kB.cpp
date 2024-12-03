#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 998244353;

void solve () {
    i64 n, ans = 1;
    std::cin >> n;

    std::vector <int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    if (arr[n - 1] != n || arr[0] > 1) {
        std::cout << "0\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        int l = (i == 0 ? 0 : arr[i - 1]);
        int d = arr[i] - l;
        if (d < 0 || d > 2) {
            std::cout << "0\n";
            return;
        } 
        if (d == 1) {
            ans = ans * (2 * i - 2 * l + 1) % mod;
        } else if (d == 2) {
            ans = ans * (i - l) % mod * (i - l) % mod;
        }
    }

    std::cout << ans << std::endl;
    return;
}

int main() {
#ifdef kimi
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}