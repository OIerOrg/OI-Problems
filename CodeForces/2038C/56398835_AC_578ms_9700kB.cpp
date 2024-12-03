#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve () {
    int n;
    cin >> n;
    map <int, int> m;
    vector <int> ve;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        m[x]++;
    }
    for (auto i : m) {
        for (int j = 0; j < i.second / 2; j++) ve.push_back(i.first);
    }
    sort (ve.begin(), ve.end());
    if (ve.size() < 4) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int a = ve[0], b = ve[ve.size() - 1];
        int c = ve[1], d = ve[ve.size() - 2];
        
        int e = ve[0], f = ve[ve.size() - 2];
        int g = ve[1], h = ve[ve.size() - 1];
        
        if (abs(a - b) * abs(c - d) <=  abs(f - e) * abs(g - h)) 
            cout << f << ' ' << g << ' ' << e << ' ' << g << ' ' << f << ' ' << h << ' ' << e << ' ' << h << '\n';
        else cout << a << ' ' << c << ' ' << a << ' ' << d << ' ' << b << ' ' << c << ' ' << b << ' ' << d << '\n';
    } 
}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
       solve();
    }
	return 0;
}