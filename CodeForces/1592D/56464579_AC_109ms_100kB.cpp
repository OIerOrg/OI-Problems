#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 1005;

int n, x, cnt = 0;

std::vector <int> edge[N];
std::vector <int> o;

void dfs (int x, int fa) {
    o.push_back(x);
    for (int i : edge[x]) {
        if (i != fa) {
            dfs (i, x);
            o.push_back(x);
        }
    }
}

int query (int l, int r) {
    std::set <int> s;
    for (int i = l; i <= r; i++) {
        s.insert (o[i]);
    }
    std::cout << "? " << s.size() << " ";
    for (int i : s) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    int x;
    std::cin >> x;
    return x;
}

int main() {
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    dfs (1, 0);
    int l = 0, r = o.size() - 1, ans;
    x = query(l, r);
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (query (l, mid) == x) {
            r = mid;
            ans = mid;
        } else {
            l = mid;
        }
    }
    std::cout << "! " << o[l] << ' ' << o[r] << std::endl; 
    return 0;
}