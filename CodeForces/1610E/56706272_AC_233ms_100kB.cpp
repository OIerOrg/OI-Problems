#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
void solve () {
    int n, ans = 1e9;
    std::cin >> n;
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (i && a[i] == a[i - 1]) continue;
    	int now = i, cnt = 0;
    	while (now < n) { 
            cnt++;
            now = lower_bound(a.begin() + now + 1, a.end(), 2 * a[now] - a[i]) - a.begin();	     
    	}
    	ans = std::min(ans, n - cnt);
    }
    std::cout << ans << std::endl;
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
