#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, t, k;
int tree[N];
bool vis[N];
void update (int i, int v) {
    for (; i <= n; i += (i & (-i))) tree[i] += v;
    return;
}

void change (int l, int r, int v) {
    update (l, v);
    if (r < n)
        update (r + 1, -v);
}

int query (int x) {
    int tmp = x;
    int ans = 0;
    for (; x; x -= (x & (-x))) ans += tree[x];
    x = tmp;
    if (!vis[x]) {
        cout << "? 1 " << x << endl;
        vis[x] = 1;
        int y;
        cin >> y;
        change (x, x, y - ans);
        return y;
    }
    return ans; 
}

bool check (int x) {
    return x - query (x) >= k;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

    cin >> n >> t;
    while (t--) {
        cin >> k;
        int l = 1, r = n, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check (mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        change(ans, n, 1);
        cout << "! " << ans << endl;
    }

	return 0;
}