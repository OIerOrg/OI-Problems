#include <bits/stdc++.h>
#define fi first
#define se second
#define multi false
#define gc getchar
#define pc putchar
#define pb push_back
#define int long long
#define pii pair <int, int>
#define debug(x) cout << #x << " " << x << '\n'
#define For(i, x, y) for (int i = (x); i <= (y); i++)
#define Rof(i, x, y) for (int i = (x); i >= (y); i--)
using namespace std;
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
inline int lcm(int a, int b) { return a * b / gcd(a, b);}
int read (char ch = ' ', int x = 0, int w = 1) { while (!isdigit(ch)) { if (ch == '-') w = -1; ch = gc(); } while (isdigit(ch)) { x = x * 10 + (ch - '0'), ch = gc(); } return x * w; }
void read(int &x) { x = read(); }
void read(int n, int a[]) {For (i, 1, n) a[i] = read();}
void read(int n, int a[], int b[]) {For (i, 1, n) a[i] = read(), b[i] = read();}
void write(int x) { if (x < 0) x = -x, pc('-'); if (x > 9) write(x / 10); pc(x % 10 + '0'); }
void write(int n, int a[]) { For (i, 1, n) write(a[i]), pc(' '); }
/*=============================================================================================================================================================================================*/
const int N = 2e5 + 10;
int t = 1, n;
void solve() {
    cin >> n;
    vector<int> a(n), r(n), l(n);
    for (auto& i : a) cin >> i;
    cout << "YES\n1 1" << endl, r[0] = 1;
    for (int i = 1; i < n; i++) {
        if (!a[i]) {
            cout << i + 1 << " 1\n", r[i] = 1, l[i] = i;
            continue;
        }
        int x = a[i] - i;
        if (x >= 0)
            cout << i + 1 << ' ' << (r[i] = x + 1) << endl;
        else
            cout << i + 1 << ' ' << (r[i] = r[l[i] = i - a[i]]) << endl;
    }
    for (int i : l) cout << i + 1 << ' ';
        cout << endl;
}
signed main() { if (multi) read(t); while (t--) solve(); return 0; }