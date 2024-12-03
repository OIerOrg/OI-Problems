#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
typedef long long LL;
 
const int N = 300010;
 
int n, m;
int g[N];
LL t[3];
 
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') 
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
 
int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        cin >> n;
        memset(t, 0, sizeof t);
        LL cnt = 0; // 三带的数量(三张相同)
        for (int i = 1; i <= n; i ++ ) 
        {
            g[i] = read();
            cnt += g[i] / 3;
            t[g[i] % 3] ++ ;
        }
        if (t[1] > cnt) cout << t[1] - cnt + cnt + t[2] << endl; // 带不走全部1
        else 
        {
            if ((cnt - t[1]) / 2 >= t[2]) // 还能带走2
            {
                LL x = cnt - t[1] - 2 * t[2]; // 剩余三带数量
                LL sum = t[1] + 2 * t[2] + x * 3 / 4; // x * 3 / 4是三带带自己
                if (x * 3 % 4 == 3) sum += 2; // 带完还剩三张相同，(不能直接输出三张相同)，就分为一个单牌和一个对子
                else if (x * 3 % 4 == 2 || x * 3 % 4 == 1) sum ++ ; // 直接输出对子/单牌
                cout << sum << endl;
            } // 带不走2
            else cout << cnt + t[2] - (cnt - t[1]) / 2 << endl;
        } // (cnt - t[1]) / 2 是还能带走2的的数量
    }
    
    return 0;
}