#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int arr[50];
int dp[50][50];
int from[50][50];
void print(int L, int R)
{
    if (L == R) cout << L << ' ';
    if (L < R)
    {
        cout << from[L][R] << ' ';
        print(L, from[L][R] - 1);
        print(from[L][R] + 1, R);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        dp[i][i] = arr[i];
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            if (dp[i + 1][j] + arr[i] > dp[i][j - 1] + arr[j])
                dp[i][j] = dp[i + 1][j] + arr[i], from[i][j] = i;
            else
                dp[i][j] = dp[i][j - 1] + arr[j], from[i][j] = j;
            for (int k = i + 1; k <= j - 1; k++)
            {
                if (dp[i][k - 1] * dp[k + 1][j] + arr[k] > dp[i][j])
                    dp[i][j] = dp[i][k - 1] * dp[k + 1][j] + arr[k], from[i][j] = k;
            }
        }
    }
    cout << dp[1][n] << '\n';
    print(1, n);
}