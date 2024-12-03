#include <bits/stdc++.h>

using i64 = long long;

constexpr int mod = 998244353;
constexpr int N = 2005;

int n, m;

std::vector <int> edge[N];
std::vector <int> buc[N];

int main() {
#ifdef kimi
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    std::vector <int> p(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> p[i];
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        edge[b].push_back(a);
    }
    for (int _ = 1; _ <= n; _++) { // 枚举的人
        std::vector <int> du(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j : edge[i]) {
                du[j]++;
            }
        }
        for (int i = 1; i <= n; i++) {
            buc[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            if (!du[i] && i != _) {
                buc[p[i]].push_back(i);
            }
        }
        std::vector <int> arr;
        for (int i = n; i >= 1; i--) { // 时间
            for (auto j : buc[i]) {
                arr.push_back(j);
            }
            if (arr.empty()) {
                std::cout << i << ' ';
                break;
            }
            int t = arr.back(); 
            arr.pop_back();
            for (int j : edge[t]) {
                if (!--du[j] && j != _) {
                    if (p[j] >= i) arr.push_back(j);
                    else buc[p[j]].push_back(j);
                }
            }
        }
    }

    return 0;
}