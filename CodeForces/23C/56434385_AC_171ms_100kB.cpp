#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

using namespace std;

struct V {
    int apple, orange, i;
    bool operator<(V s) const {
        return apple > s.apple;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;
        vector<V> a(2 * N - 1);

        i64 aleven = 0, alodd = 0;
        int tot = 2 * N - 1;

        for (int i = 0; i < tot; i++) {
            cin >> a[i].apple >> a[i].orange;
            a[i].i = i + 1;
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < tot; i += 2)
            alodd += a[i].orange;
        for (int i = 1; i < tot; i += 2)
            aleven += a[i].orange;

        cout << "YES\n";

        if (alodd > aleven) {
            for (int i = 0; i < tot; i += 2)
                cout << a[i].i << " ";
        } else {
            cout << a[0].i << " ";
            for (int i = 1; i < tot; i += 2)
                cout << a[i].i << " ";
        }
        cout << "\n";
    }

    return 0;
}