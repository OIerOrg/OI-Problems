#include <bits/stdc++.h>
#define fi first
#define se second
#define multi true
#define gc getchar
#define pc putchar
#define pb push_back
#define int long long
#define pii pair<int, int>
#define debug(x) cout << #x << " " << x << '\n'
#define For(i, x, y) for (int i = (x); i <= (y); i++)
#define Rof(i, x, y) for (int i = (x); i >= (y); i--)
using namespace std;
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
inline int lcm(int a, int b) { return a * b / gcd(a, b); }
int read(char ch = ' ', int x = 0, int w = 1) {
    while (!isdigit(ch)) {
        if (ch == '-') w = -1;
        ch = gc();
    }
    while (isdigit(ch)) { x = x * 10 + (ch - '0'), ch = gc(); }
    return x * w;
}
void read(int& x) { x = read(); }
void read(int n, int a[]) { For(i, 1, n) a[i] = read(); }
void read(int n, int a[], int b[]) { For(i, 1, n) a[i] = read(), b[i] = read(); }
void write(int x) {
    if (x < 0) x = -x, pc('-');
    if (x > 9) write(x / 10);
    pc(x % 10 + '0');
}
void write(int n, int a[]) { For(i, 1, n) write(a[i]), pc(' '); }
/*=============================================================================================================================================================================================*/
const int N = 1e5 + 10;
int t = 1;
int n, m, k;
int max_1, max_2, L, R, ans;
int a[N];
vector <int> f;
set <int> d;
void solve() {
    read(n), read(m), read(k), read(n, a);
    f.clear(); d.clear(); max_1 = max_2 = 0;
    For (i, 2, n) {
        int _ = a[i] - a[i - 1];
        if (max_1 < _) {
            max_2 = max_1;
            max_1 = _;
            L = a[i - 1], R = a[i];
        } else if (max_2 < _) max_2 = _;
    }
    For (i, 1, m) d.insert(read());
    For (i, 1, k) f.pb(read());
    ans = max_1;
    for (int i : f) {
        auto I = d.lower_bound((L + R) / 2 - i), J = I;
        ans = min(ans, max(i + *I - L, R - i - *I));
        if (J != d.begin()) {
            J--;
            ans = min(ans, max(i + *J - L, R - i - *J));
        }
    }
    write (max(ans, max_2)), pc(10);
}
signed main() {
    if (multi) read(t);
    while (t--) solve();
    return 0;
}