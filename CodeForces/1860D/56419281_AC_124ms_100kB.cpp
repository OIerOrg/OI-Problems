#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

int main() {
#ifdef kimi
    freopen("in.txt", "rr", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    
    int n = s.size();
    
    int c1 = std::count(s.begin(), s.end(), '1'), c0 = n - c1;
    
    int need = (n * (n - 1) / 2 - c0 * (c0 - 1) / 2 + c1 * (c1 - 1) / 2) / 2;
    
    std::vector dp(c1 + 1, std::vector<int>(need + 1, inf));
    dp[0][0] = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = c1 - 1; j >= 0; j--) {
            for (int k = 0; k + i <= need; k++) {
                dp[j + 1][k + i] = std::min(dp[j + 1][k + i], dp[j][k] + (s[i] == '0'));
            }
        }
    }
    std::cout << dp[c1][need] << "\n";
    
    return 0;
}