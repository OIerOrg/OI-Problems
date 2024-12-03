#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        printf("0 0 %d %d\n%d 0 0 %d\n", min(x, y), min(x, y), min(x, y), min(x, y));
    }

    return 0;
}
