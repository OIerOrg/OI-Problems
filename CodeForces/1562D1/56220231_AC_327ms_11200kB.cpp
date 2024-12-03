#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e5 + 10;
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
}
using namespace FastIO;

int t, id;
int n, m;
int arr[N];
signed main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(t); while (t--) {
        read(n, m);
        vector <int> ans[(n << 1) + 1];
        arr[0] = n; ans[n].push_back(0);
        for (int i = 1; i <= n; i++) { char c = gc();
            arr[i] = arr[i - 1] + ((c == '+') ? 1 : -1) * ((i & 1) ? 1 : -1);
            ans[arr[i]].push_back(i);
        }
        while (m--) {
            int l, r; read (l, r);
            int tmp = arr[r] - arr[l - 1];
            if (tmp == 0) {
                writeln('0');
            } 
            else if (abs(tmp) & 1) {
                int val = arr[l - 1] + tmp / 2 + (tmp > 0 ? 1 : -1);
                writeln(1);
            } else {
                tmp = arr[r - 1] - arr[l - 1];
                int val = arr[l - 1] + tmp / 2 + (tmp > 0 ? 1 : -1);
                writeln(2);
            }
        }
    }
    return 0;
}


// 计时
// 一遍过