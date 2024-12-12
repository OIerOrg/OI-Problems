#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    struct Square { i64 x, y, w; };
    std::vector<Square> s(n + 1);
    std::vector<i64> f(n + 1);
    std::vector<int> q(n + 1);
    
    auto getX = [&](int u) { return s[u].x; };
    auto getY = [&](int u) { return f[u]; };
    auto getSlope = [&](int u, int v) { 
        return std::abs(getX(v) - getX(u)) < 1e-10 ? 1e10 : (getY(v) - getY(u)) / (getX(v) - getX(u)); 
    };
    
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i].x >> s[i].y >> s[i].w;
    }
    
    std::sort(s.begin() + 1, s.end(), [](Square x, Square y) { return x.y > y.y; });
    
    int l = 1, r = 0;
    i64 ans = LLONG_MIN;
    
    for (int i = 1; i <= n; ++i) {
        while (l < r && getSlope(q[l], q[l + 1]) >= s[i].y) {
            ++l;
        }
        
        f[i] = s[i].x * s[i].y - s[i].w;
        if (l <= r) {
            f[i] = std::max(f[i], f[q[l]] + (s[i].x - s[q[l]].x) * s[i].y - s[i].w);
        }
        
        ans = std::max(ans, f[i]);
        
        while (l < r && getSlope(q[r - 1], q[r]) <= getSlope(q[r], i)) {
            --r;
        }
        
        q[++r] = i;
    }
    
    std::cout << ans << "\n";
    
    return 0;
}
