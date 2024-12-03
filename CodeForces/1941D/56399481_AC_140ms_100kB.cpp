#include <bits/stdc++.h>
const int N = 3001;
using namespace std;
int t, n, m, x, r;
int vis[N], vis2[N];
char op;
vector<int> ans;
signed main() {
    cin >> t;
    while (t--) {
        ans.clear();
        cin >> n >> m >> x;
        for (int i = 0; i < n; i++)
            vis[i] = 0;
        vis[x - 1] = 1;
        while (m--) {
            cin >> r >> op;
            if (op == 48) {
                for (int i = 0; i < n; i++)
                    vis2[i] = vis[i], vis[i] = 0;
                for (int i = 0; i < n; i++)
                    vis[(i + r) % n] = vis2[i];
            }
            else if (op == 49) {
                for (int i = 0; i < n; i++)
                    vis2[i] = vis[i], vis[i] = 0;
                for (int i = 0; i < n; i++)
                    vis[(i + n - r) % n] = vis2[i];
            }
            else if (op == 63) {
                for (int i = 0; i < n; i++)
                    vis2[i] = vis[i], vis[i] = 0;
                for (int i = 0; i < n; i++)
                    vis[(i + r) % n] = vis2[i] || vis[(i + r) % n];
                for (int i = 0; i < n; i++)
                    vis[(i + n - r) % n] = vis2[i] || vis[(i + n - r) % n];
            }
        }
        for (int i = 0; i < n; i++)
            if (vis[i] == 1)
                ans.push_back(i);
        cout << ans.size() << endl;
        for (int i : ans)
            cout << i + 1 << ' ';
        cout << endl;
    }
    return 0;
}