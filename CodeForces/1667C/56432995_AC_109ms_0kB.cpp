#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;

    if (n == 1) {
        std::cout << "1\n1 1\n";
        return 0;
    }

    int result = (2 * n - 2) / 3 + 1;
    std::cout << result << std::endl;

    int m = n;
    while (m % 3 != 2) m--;

    int k = (2 * m - 1) / 3;
    int p = 2 * k - m;
    int q = k - p;

    for (int i = 1; i <= q; i++) {
        std::cout << i << " " << q - i + 1 << std::endl;
    }
    for (int i = q + 1; i <= k; i++) {
        std::cout << i << " " << q + k - i + 1 << std::endl;
    }
    for (int i = m + 1; i <= n; i++) {
        std::cout << i << " " << i << std::endl;
    }
    return 0;
}