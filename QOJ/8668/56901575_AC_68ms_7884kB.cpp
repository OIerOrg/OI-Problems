#include <bits/stdc++.h>

using i64 = long long;
using ull = unsigned long long;

constexpr int MAXN = 1e5 + 5;

int n, ans = 0;
char s[2][MAXN];
ull B, hw[26], pw[MAXN], hs[2][MAXN], rs[2][MAXN];

// 获取前缀哈希值
ull getHash(ull *h, int l, int r) {
    return h[r] - h[l - 1] * pw[r - l + 1];
}

// 获取反转字符串的哈希值
ull getReverseHash(ull *h, int l, int r) {
    return getHash(h, n - r + 1, n - l + 1);
}

// 判断是否满足回文条件
bool isPalindrome(int l, int k, int r) {
    return getHash(hs[0], l, k) * pw[r - k + 1] + getHash(hs[1], k, r) ==
           getReverseHash(rs[1], k, r) * pw[k - l + 1] + getReverseHash(rs[0], l, k);
}

// 求解函数
void solve() {
    for (int i = 1; i <= n; ++i) { // 以 i 为中心
        int x = 0, y = 0;

        {   // 当前行扩展
            int L = 0, R = std::min(i - 1, n - i);
            while (L <= R) {
                int mid = (L + R) / 2;
                if (isPalindrome(i - mid, i + mid, i + mid - 1)) {
                    x = mid;
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }
        }

        {   // 上下行扩展
            int L = 0, R = std::min(i - x - 1, n - i - x + 1);
            while (L <= R) {
                int mid = (L + R) / 2;
                if (isPalindrome(i - x - mid, i + x, i + x + mid - 1)) {
                    y = mid;
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }
        }

        ans = std::max(ans, 2 * (x + y) + 1);
    }

    for (int i = 1; i < n; ++i) { // 以 i 和 i + 1 为中心
        if (s[0][i] == s[0][i + 1]) {
            int x = 0, y = 0;

            {   // 当前行扩展
                int L = 0, R = std::min(i, n - i);
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (isPalindrome(i + 1 - mid, i + mid, i + mid - 1)) {
                        x = mid;
                        L = mid + 1;
                    } else {
                        R = mid - 1;
                    }
                }
            }

            {   // 上下行扩展
                int L = 0, R = std::min(i - x, n - i - x + 1);
                while (L <= R) {
                    int mid = (L + R) / 2;
                    if (isPalindrome(i + 1 - x - mid, i + x, i + x + mid - 1)) {
                        y = mid;
                        L = mid + 1;
                    } else {
                        R = mid - 1;
                    }
                }
            }

            ans = std::max(ans, 2 * (x + y));
        }
    }

    for (int i = 1; i <= n; ++i) { // 以 i 和 i 为中心，跨行
        if (s[0][i] == s[1][i]) {
            int x = 0;

            int L = 0, R = std::min(i, n - i + 1);
            while (L <= R) {
                int mid = (L + R) / 2;
                if (isPalindrome(i - mid + 1, i, i + mid - 1)) {
                    x = mid;
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }

            ans = std::max(ans, 2 * x);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> (s[0] + 1) >> (s[1] + 1);
    std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
    B = rnd() | 1;

    for (int c = 0; c < 26; ++c) {
        hw[c] = rnd() | 1;
    }

    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * B;
    }

    for (int o = 0; o < 2; ++o) {
        for (int i = 1; i <= n; ++i) {
            hs[o][i] = hs[o][i - 1] * B + hw[s[o][i] - 'a'];
            rs[o][i] = rs[o][i - 1] * B + hw[s[o][n - i + 1] - 'a'];
        }
    }

    solve();
    std::swap(s[0], s[1]);
    std::swap(hs[0], rs[1]);
    std::swap(hs[1], rs[0]);
    std::reverse(s[0] + 1, s[0] + n + 1);
    std::reverse(s[1] + 1, s[1] + n + 1);
    solve();

    std::cout << ans << "\n";

    return 0;
}
