#include <iostream>
#define int long long
using namespace std;
const int N = 5e5 + 10;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n == k) {
            cout << 'A';
            continue;
        }
        if (k == 1) {
            if (n % 2 == 0) cout << 'B';
            else cout << 'A';
            continue;
        }
        cout << 'B';
    }
    return 0;
}
