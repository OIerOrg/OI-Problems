#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 M = 1e7;

int a, b, mh = 1;
int d[105], ans[105];

int gf(int ax, int bx) {
    return (int)std::ceil(double(bx) / double(ax));
}

bool dfs(int h, int m, i64 ax, i64 bx) {
    if(h == mh) {
        if(bx % ax) return false;
        d[h] = bx / ax;
        if((ans[h] == -1 || d[h] < ans[h]) && d[h] > 0) 
            std::memcpy(ans, d, (h + 1) << 2);
        return true;
    }
    if(h == mh - 1) {
        for(i64 k = 4 * bx / ax / ax + 1; k <= std::min(M / ax, M * (M - 1) / bx); ++k) {
            i64 dt = ax * ax * k * k - 4 * bx * k;
            i64 sd = std::sqrt(dt);
            if(sd * sd != dt) continue;  // sqrt(dt) 为小数
            if((ax * k - sd) & 1) continue; // 分母为小数
            i64 ta = (ax * k - sd) >> 1;
            i64 tb = (ax * k + sd) >> 1;
            if(ta > M || tb > M) return false;
            d[h] = ta;
            d[h + 1] = tb;
            if((ans[h + 1] == -1 || d[h + 1] < ans[h + 1]) && d[h + 1] > 0)
                std::memcpy(ans, d, (h + 2) << 2);
            return true;
        }
        return false;
    }
    int ff = std::max(m, gf(ax, bx));
    bool f = false;
    for(int i = ff; i * ax < bx * (mh + 1 - h)  && i <= (int)1e7; ++i) {
        d[h] = i;
        i64 by = bx * i;
        i64 ay = ax * i - bx;
        i64 gcd = std::__gcd(ay, by);
        if(dfs(h + 1, i + 1, ay / gcd, by / gcd)) f = true;
    }
    return f;
}

int main() {
    std::scanf("%d%d", &a, &b);
    std::memset(ans, -1, sizeof(ans));
    while(++mh) {
        if(dfs(0, gf(a, b), a, b)) {
            for(int i = 0; ans[i] != -1; ++i)
                std::printf("%d ", ans[i]);
            return 0;
        }
    }
}
