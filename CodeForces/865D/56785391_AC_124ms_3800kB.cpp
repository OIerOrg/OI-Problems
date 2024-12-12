#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n, x, ans = 0;
    std::cin >> n;
    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> q;
    while (n--) {
        std::cin >> x;
        q.push(x);
        if (x > q.top()) {
            ans += x - q.top();
            q.pop();
            q.push(x);
        }
    }
    std::cout << ans << '\n';
    
    return 0;
}
