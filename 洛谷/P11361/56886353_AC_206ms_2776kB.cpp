#include <bits/stdc++.h>

using i64 = long long;

void solve () {
    int n, cnt1 = 0, cnt2 = 0, ans = 0;
    std::cin >> n;
    std::string s1, s2, t1, t2;
    std::cin >> s1 >> s2 >> t1 >> t2;
    std::vector<int> bel1(n), bel2(n);
    for (int i = 0; i < n; i++) {
        if (i == 0 || t1[i] == '0' || t1[i - 1] == '0') {
            bel1[i] = cnt1++;
        } else {
            bel1[i] = bel1[i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == 0 || t2[i] == '0' || t2[i - 1] == '0') {
            bel2[i] = cnt2++;
        } else {
            bel2[i] = bel2[i - 1];
        }
    }
    std::vector <int> cnt10 (cnt1, 0), cnt11 (cnt1, 0);
    std::vector <int> cnt20 (cnt2, 0), cnt21 (cnt2, 0);
    for (int i = 0; i < n; i++) {
        if (s1[i] == '0') cnt10[bel1[i]]++;
        else              cnt11[bel1[i]]++;
        if (s2[i] == '0') cnt20[bel2[i]]++;
        else              cnt21[bel2[i]]++;
    }
    for (int i = 0; i < n; i++) {
        int &Cnt10 = cnt10[bel1[i]];
        int &Cnt11 = cnt11[bel1[i]];
        int &Cnt20 = cnt20[bel2[i]];
        int &Cnt21 = cnt21[bel2[i]];
        int Use0 = std::min(Cnt10, Cnt20);
        int Use1 = std::min(Cnt11, Cnt21);
        ans += Use0 + Use1;
        Cnt10 -= Use0;
        Cnt20 -= Use0;
        Cnt11 -= Use1;
        Cnt21 -= Use1;
        if (Cnt10 && Cnt21) {
            int x = std::min(Cnt10, Cnt21);
            Cnt10 -= x;
            Cnt21 -= x;
        }
        if (Cnt11 && Cnt20) {
            int x = std::min(Cnt11, Cnt20);
            Cnt11 -= x;
            Cnt20 -= x;
        }
    }
    std::cout << ans << std::endl;
}

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
