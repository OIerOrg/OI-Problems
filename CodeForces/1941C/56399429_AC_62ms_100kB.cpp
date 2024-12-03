#include <bits/stdc++.h>
using namespace std;
int t, n, ans;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n >> s;
        s = " " + s;
        for (int i = 1; i <= n; i++) {
            if (i >= 3 && s[i - 2] == 'm' && s[i - 1] == 'a' && s[i] == 'p') ans++;
            else if (i <= n - 2 && s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e') ans++;
        }
        cout << ans << '\n';
    }
}
// map pie