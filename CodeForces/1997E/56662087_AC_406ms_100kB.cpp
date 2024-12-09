#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick {
    const int n;
    std::vector<T> a;
    Fenwick(int n) : n(n + 1), a(n + 1) {}
    void add(int x, T v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector <int> a(n + 1), Ans(n + 1);
    Fenwick <int> tree(n);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (1ll * a[i] * mid <= tree.sum(mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        tree.add (l, 1);
        Ans[i] = l;
    }
    for (int i = 1; i <= q; i++) {
        int x, k;
        std::cin >> x >> k; 
        std::cout << (k < Ans[x] ? "NO" : "YES") << std::endl;
    }
    return 0;
}
