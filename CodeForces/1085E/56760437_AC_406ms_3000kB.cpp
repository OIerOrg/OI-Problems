#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int k, n;
int8_t S[maxn], A[maxn], B[maxn], to[128];
bool vis[128];
bool sol(int i, bool tl, bool tr) {
    if (!S[i]) return 1;
    auto &c = to[S[i]], a = A[i], b = B[i];
    if (c) {
        if (tl && c < a) return 0;
        if (tr && c > b) return 0;
        return sol(i + 1, tl && c == a, tr && c == b);
    }
    for (c = (tl ? a : 'a'); c <= (tr ? b : 'a' + k - 1); ++c)
        if (!vis[c]) {
            vis[c] = 1;
            if (sol(i + 1, tl && c == a, tr && c == b)) return 1;
            vis[c] = 0;
        }
    c = 0;
    return 0;
}
void sol() {
    cin >> k >> (char(&)[maxn])S[1] >> (char(&)[maxn])A[1] >> (char(&)[maxn])B[1];
    n = strlen((char*)A + 1);
    memset(to, 0, sizeof to);
    memset(vis, 0, sizeof vis);
    if (sol(1, 1, 1)) {
        int i = 'a';
        for (int j = 'a'; j < 'a' + k; ++j)
            if (!to[j]) {
                while (vis[i]) ++i;
                to[j] = i;
                vis[i] = 1;
            }
        cout << "YES\n"
             << (char(&)[maxn])to['a'] << '\n';
    } else
        cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) sol();
}