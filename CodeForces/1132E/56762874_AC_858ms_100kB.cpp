#include <bits/stdc++.h>

using i64 = long long;

i64 n, max;
std::vector <i64> a(8);

void dfs (int x, i64 sum) {
    if (x == 8) {
        max = std::max(max, sum);
        return;
    }
    i64 b = std::min(a[x], (n - sum) / (x + 1));
    for (i64 i = b; i >= std::max(0ll, b - 10); i--) {
        dfs (x + 1, sum + i * (x + 1));
    }
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for (i64 &i : a) std::cin >> i;
    dfs (0, 0);
    std::cout << max << std::endl;
    return 0;
}
