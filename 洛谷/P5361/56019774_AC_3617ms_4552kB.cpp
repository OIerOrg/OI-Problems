#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 5;
int n, m;
vector<int> g[maxn];
int deg[maxn];
bool vis[maxn];

void dfs(int u, int p)
{
    vis[u] = true;
    for (int v : g[u])
    {
        if (!vis[v])
        {
            deg[v]--;
            if (deg[v] < p)
                dfs(v, p);
        }
    }
}

void check(int p)
{
    fill(vis, vis + n + 1, false);
    for (int i = 1; i <= n; i++)
        deg[i] = g[i].size();
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && deg[i] < p)
            dfs(i, p);
    }
}

int ord[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l + 1) / 2;
            check(mid);
            bool ok = false;
            for (int i = 1; i <= n; i++)
            {
                if (!vis[i])
                {
                    ok = true;
                    break;
                }
            }
            if (ok)
                l = mid;
            else
                r = mid - 1;
        }

        check(r);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (!vis[i])
                cnt++;

        printf("%d ", cnt);
        for (int i = 1; i <= n; i++)
            if (!vis[i])
                printf("%d ", i);
        printf("\n");

        for (int i = 1; i <= n; i++)
            ord[i] = i;
        random_shuffle(ord + 1, ord + n + 1);

        fill(vis, vis + n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            bool ok = true;
            for (int v : g[ord[i]])
            {
                if (vis[v])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                vis[ord[i]] = true;
        }

        cnt = 0;
        for (int i = 1; i <= n; i++)
            if (vis[i])
                cnt++;

        printf("%d ", cnt);
        for (int i = 1; i <= n; i++)
            if (vis[i])
                printf("%d ", i);
        printf("\n");
    }

    return 0;
}
