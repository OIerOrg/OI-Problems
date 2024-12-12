#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 n, c;
    std::cin >> n >> c;
    std::vector<i64> h(n), f(n);
    std::deque <int> q;
    std::function <double(int, int)> slope = [&](int i, int j) {
        return 1.0 * (f[i] + h[i] * h[i] - f[j] - h[j] * h[j]) / (h[i] - h[j]);
    };
    for (int i = 0; i < n; i++) std::cin >> h[i];
    q.push_back(0);
    for (int i = 1; i < n; i++) {
        while (q.size() > 1) {
            int a = q.front(); q.pop_front();
            int b = q.front(); q.push_front(a);
            if (slope(a, b) <= 2 * h[i]) q.pop_front();
            else break;
        }
        int j = q.front();
        f[i] = f[j] + (h[i] - h[j]) * (h[i] - h[j]) + c;
        while (q.size() > 1) {
            int b = q.back(); q.pop_back();
            int a = q.back(); q.push_back(b);
            if (slope(a, b) >= slope(b, i)) q.pop_back();
            else break;
        }
        q.push_back(i);
    }
    std::cout << f[n - 1];
    return 0;
} 