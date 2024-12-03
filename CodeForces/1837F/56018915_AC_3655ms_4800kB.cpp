#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
#define int long long
int q, n, k;
int ans;
int a[maxn];
int l, r;
int need[maxn];  // Declare `need` array globally
#define pq priority_queue

bool check(int mid) {
    pq<int> q;
    int sum = 0;

    // Calculate `need[i]` values for the first pass
    for (int i = 1; i <= n; ++i) {
        q.push(a[i]);
        sum += a[i];
        while (sum > mid) {
            sum -= q.top();
            q.pop();
        }
        need[i] = q.size();
    }

    sum = 0;
    while (!q.empty()) q.pop();

    // Check the second pass, using `need[i-1]` values
    for (int i = n; i > 0; --i) {
        q.push(a[i]);
        sum += a[i];
        while (sum > mid) {
            sum -= q.top();
            q.pop();
        }
        if (q.size() + need[i - 1] >= k)  // need[i-1] 注意边界
            return true;
    }

    return false;
}

signed main() {
    cin >> q;
    while (q--) {
        l = 0;
        r = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            r += a[i];
        }

        // Binary search to find the minimum valid sum
        while (l <= r) {
            int mid_qwq = (l + r) >> 1;
            if (check(mid_qwq)) {
                r = mid_qwq - 1;
                ans = mid_qwq;
            } else {
                l = mid_qwq + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
