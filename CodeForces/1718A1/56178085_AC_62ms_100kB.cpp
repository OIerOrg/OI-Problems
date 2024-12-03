#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 10;
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
        int n, s = 0, ans;
        set <int> st; st.insert (0);
        cin >> n; ans = n;
        while (n--) {
            int x; cin >> x;
            s ^= x; if (st.find(s) != st.end()) {
                ans--;
                st.clear();
                st.insert (s = 0);
            } else {
                st.insert(s);
            }
        }
        cout << ans << '\n';

    }
	return 0;
}