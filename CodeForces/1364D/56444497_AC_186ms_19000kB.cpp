#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 9;
int n, m, k, cnt, mm;
int vis[N];
pair <int, int> edges[N];
vector <int>  Edge[N], ans[2], Ans;
queue <int> q;
stack <int> st;
void dfs_tree (int x, int i, int fa) {
    ans[i].push_back(x);
    for (int j : Edge[x]) if (j != fa) dfs_tree (j, 1 - i, x);
}
void dfs_c (int x, int fa) {
    st.push(x); vis[x] = 1;
    for (int i : Edge[x]) {
        if (i == fa) continue;
        if (vis[i]) {
            while (st.top() != i) {
                Ans.push_back(st.top());
                st.pop();
            }
            Ans.push_back(i);
            cout << Ans.size() << endl;
            for (int j : Ans) cout << j << ' '; cout << '\n';
            exit(0);
        } else {
            dfs_c (i, x);
        }
    }
    st.pop();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef kimi
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
    	cin >> edges[i].first >> edges[i].second;
    	Edge[edges[i].first].push_back(edges[i].second);
    	Edge[edges[i].second].push_back(edges[i].first);
    }
    q.push(1); cnt = 1, vis[1] = 1;
    while (q.size()) {
    	int top = q.front(); q.pop();
    	for (int i : Edge[top]) {
    		if (!vis[i]) {
    			q.push(i);
    			vis[i] = true, cnt++;
    			if (cnt == k) break;
    		}
    	}
    	if (cnt == k) break;
    }
    for (int i = 1; i <= n; i++) Edge[i].clear();
    for (int i = 1; i <= m; i++) {
        if (vis[edges[i].first] && vis[edges[i].second]) {
            Edge[edges[i].first].push_back(edges[i].second);
            Edge[edges[i].second].push_back(edges[i].first);
            mm++;
        }
    } m = mm;
    for (int i = 1; i <= n; i++) vis[i] = 0;
    if (m + 1 == k) { // tree
        dfs_tree(1, 0, 0);
        cout << "1\n";
        if (ans[0].size() >= (k + 1) / 2) for (int i = 0; i < (k + 1) / 2; i++) cout << ans[0][i] << ' '; 
        else for (int i = 0; i < (k + 1) / 2; i++) cout << ans[1][i] << ' '; cout << '\n';
    } else { // 找随便一个环
        cout << "2\n";
        dfs_c (1, 0);
    }
    return 0;
}
// 10:27 ~ 