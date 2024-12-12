#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int t = 0;
    std::vector<int> ti(n);
    for (int i = 0; i < n; i++) {
        std::cin >> ti[i];
        t = std::max(t, ti[i]);
    }

    std::vector<int> cnt(t + m + 1, 0), sum(t + m + 1, 0), f(t + m + 1, std::numeric_limits<int>::max());

    for (int i = 0; i < n; i++) {
        cnt[ti[i]]++;
        sum[ti[i]] += ti[i];
    }

    for (int i = 1; i < t + m; i++) {
        cnt[i] += cnt[i - 1];
        sum[i] += sum[i - 1];
    }

    f[0] = 0;
    for (int i = 1; i < t + m; i++) {
        f[i] = cnt[i] * i - sum[i];
        for (int j = std::max(0, i - 2 * m); j <= i - m; j++) {
            f[i] = std::min(f[i], f[j] + (cnt[i] - cnt[j]) * i - (sum[i] - sum[j]));
        }
    }

    int ans = std::numeric_limits<int>::max();
    for (int i = t; i < t + m; i++) {
        ans = std::min(ans, f[i]);
    }

    std::cout << ans << "\n";
    return 0;
}
