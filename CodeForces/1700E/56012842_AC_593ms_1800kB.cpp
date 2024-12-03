#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool ok(const vector<vector<int>>& a, int i, int j, int n, int m) {
    return a[i][j] == 1 ||
           (j > 0 && a[i][j-1] < a[i][j]) ||
           (j + 1 < m && a[i][j+1] < a[i][j]) ||
           (i > 0 && a[i-1][j] < a[i][j]) ||
           (i + 1 < n && a[i+1][j] < a[i][j]);
}

bool ok2(const vector<vector<int>>& a, int i, int j, int n, int m) {
    return ok(a, i, j, n, m) &&
           (j == 0 || ok(a, i, j-1, n, m)) &&
           (j + 1 == m || ok(a, i, j+1, n, m)) &&
           (i == 0 || ok(a, i-1, j, n, m)) &&
           (i + 1 == n || ok(a, i+1, j, n, m));
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<pair<int, int>> badPos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!ok(a, i, j, n, m)) {
                badPos.push_back({i, j});
            }
        }
    }

    if (badPos.empty()) {
        cout << 0 << endl;
        return 0;
    }

    set<pair<int, int>> ans;
    auto swapCells = [&](int x1, int y1, int x2, int y2) {
        swap(a[x1][y1], a[x2][y2]);
    };

    int bi = badPos[0].first, bj = badPos[0].second;
    vector<pair<int, int>> neighbors = {{bi, bj}, {bi, bj - 1}, {bi, bj + 1}, {bi - 1, bj}, {bi + 1, bj}};
    
    for (auto& p : neighbors) {
        int x = p.first, y = p.second;
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                swapCells(x, y, i, j);
                
                bool allGood = true;
                for (auto& q : badPos) {
                    if (!ok(a, q.first, q.second, n, m)) {
                        allGood = false;
                        break;
                    }
                }
                if (allGood) {
                    if (ok2(a, x, y, n, m) && ok2(a, i, j, n, m)) {
                        ans.insert({min(x * m + y, i * m + j), max(x * m + y, i * m + j)});
                    }
                }
                
                swapCells(x, y, i, j); // revert swap
            }
        }
    }

    if (!ans.empty()) {
        cout << 1 << " " << ans.size() << endl;
    } else {
        cout << 2 << endl;
    }

    return 0;
}