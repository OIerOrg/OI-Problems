// n = len of string
// 1 - (n - 1) the node between the char
// n - n + 511 the super node 
#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#else
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#endif
    std::string s;
    std::cin >> s;
    int n = s.size(), tot = n;
    std::array <std::array <int, 26>, 26> id;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            id[i][j] = tot++;
        }
    }
    std::array <std::vector <int>, 676> dist; 
    std::vector <std::vector<std::pair <int, int>>> e(tot);
    e[1].push_back({id[s[0] - 'a'][s[1] - 'a'], 0});
    e[id[s[0] - 'a'][s[1] - 'a']].push_back({1, 1});
    for (int i = 2; i < n; i++) {
        e[i - 1].push_back({i, 1});
        e[i].push_back({i - 1, 1});
        e[i].push_back({id[s[i - 1] - 'a'][s[i] - 'a'], 0});
        e[id[s[i - 1] - 'a'][s[i] - 'a']].push_back({i, 1});
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            dist[id[i][j] - n].resize(tot);
            fill(dist[id[i][j] - n].begin(), dist[id[i][j] - n].end(), 1e9);
            std::deque <int> q;
            q.push_back(id[i][j]);
            dist[id[i][j] - n][id[i][j]] = 0;
            while (!q.empty()) {
                int top = q.front(); q.pop_front();
                for (auto [to, weight] : e[top]) {
                    if (dist[id[i][j] - n][to] > dist[id[i][j] - n][top] + weight) {
                        dist[id[i][j] - n][to] = dist[id[i][j] - n][top] + weight;
                        if (weight == 1) {
                            q.push_back(to);
                        } else {
                            q.push_front(to);
                        }
                    }
                }
            }
        }
    }
    int m;
    std::cin >> m;
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        int ans = abs(x - y);
        for (int i = 0; i < 676; ++i) {
            ans = std::min(ans, dist[i][x] + dist[i][y] - 1);    
        }
        std::cout << ans << std::endl;
    }
    return 0;
}