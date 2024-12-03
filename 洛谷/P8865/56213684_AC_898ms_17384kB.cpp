#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
const int M = 1e3 + 10;
const int Lg = 30;
const int mod1 = 1e9 + 7;
const int mod9 = 998244353;

namespace FastIO {
char gc() {
    char c;
    c = getchar();
    while (c == '\n' || c == '\r' || c == ' ') c = getchar();
    return c;
}
template <class T = int> inline T read() {
    T x = 0;
    bool is_negative = 0;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') is_negative = 1;
        ch = getchar(); }
    while (isdigit(ch)) x = x * 10 + (ch & 15), ch = getchar();
    return is_negative ? -x : x;
}
template <class T> inline void read(T& x) { x = read<T>(); }
template <class T, class... R> inline void read(T& x, R&... args) { read(x), read(args...); }
template <class T> inline void read_arr(T* arr_begin, const T* arr_end) { while (arr_begin < arr_end) *arr_begin++ = read<T>(); }
template <class T> inline void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (!x) return putchar('0'), void();
    static int digits[39];
    int cnt = 0;
    while (x) digits[cnt++] = x % 10, x /= 10;
    for (int i = cnt - 1; i >= 0; --i) putchar(digits[i] | 48);
}
inline void write(const char ch) { putchar(ch); }
template <class T, class... R> inline void write(const T x, R... args) { write(x), putchar(32), write(args...); }
template <class... R> inline void writeln(R... args) { write(args...), putchar('\n'); }
template <class T, class... R> inline void err(const T x, R... args) { printf ("|<= debug =>|"); writeln(x, args...); }
}
using namespace FastIO;

int t, id;
int n, m, cc, ff;

bool mp[M][M];
int mxr[M][M];
int mxd[M][M];
int c () {
    int ans = 0;
    for (int j = 1; j < m; j++) {
        int now = 0;
        for (int i = 1; i <= n; i++) {
            if (mp[i][j]) { now = 0; continue; }
            (ans += now * (mxr[i][j] - 1)) %= mod9;
            if (i != 1 && mp[i - 1][j] == 0) (now += mxr[i - 1][j] - 1) %= mod9;
        }
    }
    return ans * cc;
}

int f () {
    int ans = 0;
    for (int j = 1; j < m; j++) {
        int now = 0;
        for (int i = 1; i <= n; i++) {
            if (mp[i][j]) { now = 0; continue; }
            (ans += now * (mxr[i][j] - 1) % mod9 * (mxd[i][j] - 1)) %= mod9;
            if (i != 1 && mp[i - 1][j] == 0) (now += mxr[i - 1][j] - 1) %= mod9;
        }
    }
    return ans * ff;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read (t, id);
    while (t--) {
        read (n, m, cc, ff);
        for (int i = 1; i <= n + 1; i++)
            for (int j = 1; j <= m + 1; j++)
                mxr[i][j] = mxd[i][j] = 0;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++)
                mp[i][j] = gc() - '0';
        for (int j = m; j; j--) 
            for (int i = 1; i <= n; i++) {
                if (mp[i][j]) mxr[i][j] = 0;
                else mxr[i][j] = mxr[i][j + 1] + 1;
            }
        for (int i = n; i; i--) 
            for (int j = 1; j <= m; j++) {
                if (mp[i][j]) mxd[i][j] = 0;
                else mxd[i][j] = mxd[i + 1][j] + 1;
            }
        writeln(c(), f());
    }
    return 0;
}


// 计时
// 一遍过