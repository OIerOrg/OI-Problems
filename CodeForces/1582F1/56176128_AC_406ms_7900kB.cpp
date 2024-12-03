#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n;
int arr[N], f[N];
vector <int> ans(1, 0);
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= 512; i++) f[i] = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 512; j++) {
            if (f[j] < arr[i]) {
                if (f[j xor arr[i]] == 1e9) {
                    ans.push_back (j xor arr[i]);
                }
                f[j xor arr[i]] = min(f[j xor arr[i]], arr[i]);

            }
        }
    }
    sort (ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
	return 0;
}
