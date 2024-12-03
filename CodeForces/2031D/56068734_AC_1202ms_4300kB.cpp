#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ar(n), pref(n), suff(n), ans(n);
        for (int i = 0; i < n; i++) cin >> ar[i];
        pref[0] = ar[0];
        for (int i = 1; i < n; i++) pref[i] = max(pref[i - 1], ar[i]);
        suff[n - 1] = ar[n - 1];
        for (int i = n - 2; i >= 0; i--) suff[i] = min(suff[i + 1], ar[i]);
        ans[n - 1] = pref[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (pref[i] > suff[i + 1])
                ans[i] = ans[i + 1];
            else
                ans[i] = pref[i];
        }

        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}