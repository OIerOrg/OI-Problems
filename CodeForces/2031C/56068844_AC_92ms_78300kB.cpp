#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 10;
int n, ans = 1e9;
int arr[N];
int main() {
#ifdef kimi
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        if ((n & 1) && n <= 25) cout << "-1\n";
        else if (n & 1) {
            cout << "1 2 2 3 3 4 4 5 5 1 6 6 7 7 8 8 9 9 10 10 11 11 12 13 13 1 12 ";
            for (int i = 28; i <= n; i += 2) cout << i << ' ' << i << ' '; 
            cout << '\n';
        }
        else {
            for (int i = 1; i <= n; i += 2) cout << i << ' ' << i << ' ';
            cout << '\n';
        }
    }
    return 0;
}