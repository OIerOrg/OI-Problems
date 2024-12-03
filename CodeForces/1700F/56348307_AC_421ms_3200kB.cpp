#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 5;
int n, a[2][N], b[2][N];
LL sum, Ans;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[0][i]), sum += a[0][i];
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[1][i]), sum += a[1][i];
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[0][i]), sum -= b[0][i];
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[1][i]), sum -= b[1][i];
    if (sum)
    {
        printf("-1");
        return 0;
    }
    LL s0 = 0, s1 = 0;
    for (int i = 1; i <= n; i++)
    {
        s0 += a[0][i] - b[0][i], s1 += a[1][i] - b[1][i];
        if (s0 < 0 && s1 > 0)
        {
            int nm = min(-s0, s1);
            Ans += nm;
            s0 += nm, s1 -= nm;
        }
        else if (s0 > 0 && s1 < 0)
        {
            int nm = min(s0, -s1);
            Ans += nm;
            s0 -= nm, s1 += nm;
        }
        Ans += abs(s0) + abs(s1);
    }
    printf("%lld", Ans);
    return 0;
}