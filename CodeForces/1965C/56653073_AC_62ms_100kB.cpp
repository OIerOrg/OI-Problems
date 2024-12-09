#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    int l = 0, r = 0;
    int x = s[0] - '0';
    int i = 0;
    for (auto c : s) {
        if (c - '0' == (x + i % 2 + 2) % 2) {
            i++;
            r = std::max(r, i);
        } else {
            i--;
            l = std::min(l, i);
        }
    }
    std::cout << r - l << "\n";
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