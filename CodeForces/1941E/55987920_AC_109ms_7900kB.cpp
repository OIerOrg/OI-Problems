#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 105;
const int N = 1e6 + 10;
int t, n, m, k, d, ans;
vector <int> arr[M];
int ddp[M], dp[N], sum[M];
deque<int>de;
int solve(int x) {
    de.clear();
    de.push_back(1);
    dp[1] = 1;
    for (int i = 2; i <= m; i++) {
        while(de.size() && de.front() < i - d - 1) de.pop_front();
        dp[i] = dp[de.front()] + arr[x][i] + 1;
        while(de.size() && dp[i] <= dp[de.back()]) de.pop_back();
        de.push_back(i);
    }
    return dp[m] - arr[x][m] - 1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) {
        ans = LLONG_MAX;
        cin >> n >> m >> k >> d;
        for (int i = 1; i <= n; i++) {
            arr[i].resize(m + 1);
            for (int j = 1; j <= m; j++) 
                cin >> arr[i][j];
        }
        for (int i = 1; i <= n; i++) 
            ddp[i] = solve(i), sum[i] = sum[i - 1] + ddp[i];
        for (int i = 1; i <= n - k + 1; i++)
            ans = min(ans, sum[i + k - 1] - sum[i - 1]);
        cout << ans + k << '\n';
    }
}