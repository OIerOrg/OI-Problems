#include <bits/stdc++.h>

using i64 = long long;

int dp[200005][2][2][2][2][2][2];

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    memset(dp, -1, sizeof dp);
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::function<int(int, bool, bool, bool, bool, bool, bool)> dfs = [&](int k, bool la, bool lb, bool lc, bool oka, bool okb, bool okc) -> int {
        int& now = dp[k][la][lb][lc][oka][okb][okc];
        if (k == n) {
            return now = (oka && okb && okc);
        }
        if (now != -1) return now;
        now = 0;
        for (int a = 0; a <= (la ? s[k] - '0' : 1); a++) {
            for (int b = 0; b <= (lb ? s[k] - '0' : 1); b++) {
                for (int c = 0; c <= (lc ? s[k] - '0' : 1); c++) {
                    now += dfs(k + 1, la && (a == s[k] - '0'), 
                                      lb && (b == s[k] - '0'), 
                                      lc && (c == s[k] - '0'), 
                                      oka || ((a ^ b) + (a ^ c) > (b ^ c)), 
                                      okb || ((b ^ a) + (b ^ c) > (a ^ c)), 
                                      okc || ((c ^ a) + (c ^ b) > (a ^ b)));
                    now %= 998244353;
                }
            }
        }
        return now;
    };
    std::cout << dfs(0, 1, 1, 1, 0, 0, 0);
    return 0;
}