#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, x, y, ans;
vector<int> edge[N];

int siz[N], f[N], dp[N];
void dfs(int x, int fa)
{
    siz[x] = 1;
    for (int i : edge[x])
    {
        if (i != fa)
        {
            dfs(i, x);
            siz[x] += siz[i];
            f[x] += f[i];
        }
    }
    f[x] += siz[x];
    return;
}

void dfs2(int x, int fa)
{
    for (int i : edge[x]) 
    {
        if (i != fa) {
            dp[i] = dp[x] - siz[i] * 2 + n;
            ans = max(ans, dp[i]);
            dfs2(i, x);
        }
    }
    return;
}

signed main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    dfs(1, 0);

    ans = dp[1] = f[1];

    dfs2(1, 0);

    cout << ans << '\n';
}