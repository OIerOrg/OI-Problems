#include <bits/stdc++.h>

using i64 = long long;

int calc (int n, int sq, std::vector <int> &arr) {
    int res = 0;
    std::vector <int> cnt (sq * sq + sq * n, 0);
    for (int i = 0; i <= sq; i++) { // 枚举公差 
        for (int j = 0; j < n; j++) {
            res = std::max(res, ++cnt[arr[j] + (n - j - 1) * i]);
        }
        for (int j = 0; j < n; j++) {
            --cnt[arr[j] + (n - j - 1) * i];
        }
    }

    std::vector <std::unordered_map <int, int>> f(n);
    for (int i = 0; i < n; i++) { // dp
        for (int j = std::max(0, i - sq); j < i; j++) {
            if ((arr[i] - arr[j]) % (j - i) == 0) {
                int x = (arr[i] - arr[j]) / (j - i);
                if (x <= sq) continue; // 不在研究范围之内
                f[i][x] = std::max(f[i][x], f[j][x] + 1);
                res = std::max(res, f[i][x] + 1);
            }
        }
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, max = 0, sq;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
        max = std::max(max, arr[i]);
    }

    sq = std::sqrt(max) + 1;

    int ans1 = calc (n, sq, arr);

    reverse (arr.begin(), arr.end());

    int ans2 = calc (n, sq, arr);

    std::cout << std::min(n - ans1, n - ans2) << std::endl;
    return 0;
}
