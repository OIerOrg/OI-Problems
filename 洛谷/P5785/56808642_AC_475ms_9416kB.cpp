#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, l = 1, r = 0;
    i64 s, sc[300005], st[300005], f[300005], q[300005];
    
    std::cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        std::cin >> st[i] >> sc[i];
        st[i] += st[i - 1];
        sc[i] += sc[i - 1];
    }

    auto Y = [&](int p) { return f[p]; };
    auto X = [&](int p) { return sc[p]; };
    auto K = [&](int p) { return s + st[p]; };

    auto Search = [&](int L, int R, i64 S) -> int {
        int M = 0, Res = r;
        while (L <= R) {
            M = (L + R) >> 1;
            if (Y(q[M + 1]) - Y(q[M]) > S * (X(q[M + 1]) - X(q[M])))
                R = M - 1, Res = M;
            else
                L = M + 1;
        }
        return q[Res];
    };

    q[++r] = 0;
    for (int i = 1; i <= n; ++i) {
        int p = Search(l, r, K(i));
        f[i] = f[p] + s * (sc[n] - sc[p]) + st[i] * (sc[i] - sc[p]);
        while (l < r && (Y(q[r]) - Y(q[r - 1])) * (X(i) - X(q[r])) >= (Y(i) - Y(q[r])) * (X(q[r]) - X(q[r - 1]))) 
            --r;
        q[++r] = i;
    }

    std::cout << f[n] << '\n';
    return 0;
}
