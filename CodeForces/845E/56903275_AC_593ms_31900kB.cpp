// @Author: @qmwneb 
// @Language: C++14 
// @Date: Sat 11/23/2024 
// @Time: 07:54 AM
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e3 + 10;
const int M = 1e3 + 10;
const int Lg = 30;
const int mod1 = 1e9 + 7;
const int mod9 = 998244353;
namespace FastIO {
namespace Fread {
const int SIZE = 1 << 16;
char buf[SIZE], *S, *T;
inline char getchar() {
    if (S == T) {
        T = (S = buf) + fread(buf, 1, SIZE, stdin);
        if (S == T) return '\n';
    }
    return *S++;
}
}
namespace Fwrite {
const int SIZE = 1 << 16;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush() {
    fwrite(buf, 1, S - buf, stdout);
    S = buf;
}
inline void putchar(char c) {
    *S++ = c;
    if (S == T) flush();
}
struct NTR {
    ~NTR() { flush(); }
} ztr;
}
#define getchar Fread::getchar
#define putchar Fwrite::putchar
int print_precision = 10;
bool print_T_endl = 1;
char print_between = ' ';
template <typename T>
struct is_char {
    static constexpr bool value = (std::is_same<T, char>::value || std::is_same<T, signed char>::value || std::is_same<T, unsigned char>::value);
};
template <typename T>
struct is_integral_ex {
    static constexpr bool value = (std::is_integral<T>::value || std::is_same<T, __int128>::value) && !is_char<T>::value;
};
template <typename T>
struct is_floating_point_ex {
    static constexpr bool value = std::is_floating_point<T>::value || std::is_same<T, __float128>::value;
};
namespace Fastio {
struct Reader;
struct Writer;
template <size_t id>
struct read_tuple {
    template <typename... T>
    static void read(Reader& stream, std::tuple<T...>& x) {
        read_tuple<id - 1>::read(stream, x);
        stream >> get<id - 1>(x);
    }
};
template <>
struct read_tuple<0> {
    template <typename... T>
    static void read([[maybe_unused]] Reader& stream, [[maybe_unused]] std::tuple<T...>& x) { }
};
template <size_t id>
struct print_tuple {
    template <typename... T>
    static void print(Writer& stream, const std::tuple<T...>& x) {
        print_tuple<id - 1>::print(stream, x);
        putchar(print_between);
        stream << get<id - 1>(x);
    }
};
template <>
struct print_tuple<1> {
    template <typename... T>
    static void print(Writer& stream, const std::tuple<T...>& x) { stream << get<0>(x); }
};
template <>
struct print_tuple<0> {
    template <typename... T>
    static void print([[maybe_unused]] Writer& stream, [[maybe_unused]] const std::tuple<T...>& x) { }
};
struct Reader {
    template <typename T>
    typename std::enable_if_t<std::is_class<T>::value, Reader&> operator>>(T& x) {
        for (auto& y : x) *this >> y;
        return *this;
    }
    template <typename... T>
    Reader& operator>>(std::tuple<T...>& x) {
        read_tuple<sizeof...(T)>::read(*this, x);
        return *this;
    }
    template <typename T>
    typename std::enable_if_t<is_integral_ex<T>::value, Reader&> operator>>(T& x) {
        char c = getchar();
        short f = 1;
        while (c < '0' || c > '9') {
            if (c == '-') f *= -1;
            c = getchar();
        }
        x = 0;
        while (c >= '0' && c <= '9') {
            x = (x << 1) + (x << 3) + (c ^ 48);
            c = getchar();
        }
        x *= f;
        return *this;
    }
    template <typename T>
    typename std::enable_if_t<is_floating_point_ex<T>::value, Reader&> operator>>(T& x) {
        char c = getchar();
        short f = 1, s = 0;
        x = 0;
        T t = 0;
        while ((c < '0' || c > '9') && c != '.') {
            if (c == '-') f *= -1;
            c = getchar();
        }
        while (c >= '0' && c <= '9' && c != '.') x = x * 10 + (c ^ 48), c = getchar();
        if (c == '.')
            c = getchar();
        else
            return x *= f, *this;
        while (c >= '0' && c <= '9') t = t * 10 + (c ^ 48), s++, c = getchar();
        while (s--) t /= 10.0;
        x = (x + t) * f;
        return *this;
    }
    template <typename T>
    typename std::enable_if_t<is_char<T>::value, Reader&> operator>>(T& c) {
        c = getchar();
        while (c == '\n' || c == ' ' || c == '\r') c = getchar();
        return *this;
    }
    Reader& operator>>(char* str) {
        int len = 0;
        char c = getchar();
        while (c == '\n' || c == ' ' || c == '\r') c = getchar();
        while (c != '\n' && c != ' ' && c != '\r') str[len++] = c, c = getchar();
        str[len] = '\0';
        return *this;
    }
    template <typename T1, typename T2>
    Reader& operator>>(std::pair<T1, T2>& x) {
        *this >> x.first >> x.second;
        return *this;
    }
    Reader& operator>>(std::string& str) {
        str.clear();
        char c = getchar();
        while (c == '\n' || c == ' ' || c == '\r') c = getchar();
        while (c != '\n' && c != ' ' && c != '\r') str.push_back(c), c = getchar();
        return *this;
    }
    Reader() { }
} cin;
const char endl = '\n';
struct Writer {
    typedef __int128 mxdouble;
    template <typename T>
    typename std::enable_if_t<std::is_class<T>::value, Writer&> operator<<(const T& x) {
        for (auto q : x) {
            *this << q;
            if (!is_class<decltype(q)>::value) *this << print_between;
        }
        if (!is_class<typename T::value_type>::value && print_T_endl) *this << '\n';
        return *this;
    }
    template <typename... T>
    Writer& operator<<(const std::tuple<T...>& x) {
        print_tuple<sizeof...(T)>::print(*this, x);
        if (print_T_endl) *this << '\n';
        return *this;
    }
    template <typename T>
    typename std::enable_if_t<is_integral_ex<T>::value, Writer&> operator<<(T x) {
        if (x == 0) return putchar('0'), *this;
        if (x < 0) putchar('-'), x = -x;
        static int sta[45];
        int top = 0;
        while (x) sta[++top] = x % 10, x /= 10;
        while (top) putchar(sta[top] + '0'), --top;
        return *this;
    }
    template <typename T>
    typename std::enable_if_t<is_floating_point_ex<T>::value, Writer&> operator<<(T x) {
        if (x < 0) putchar('-'), x = -x;
        x += pow(10, -print_precision) / 2;
        mxdouble _ = x;
        x -= (T)_;
        static int sta[45];
        int top = 0;
        while (_) sta[++top] = _ % 10, _ /= 10;
        if (!top) putchar('0');
        while (top) putchar(sta[top] + '0'), --top;
        putchar('.');
        for (int i = 0; i < print_precision; i++) x *= 10;
        _ = x;
        while (_) sta[++top] = _ % 10, _ /= 10;
        for (int i = 0; i < print_precision - top; i++) putchar('0');
        while (top) putchar(sta[top] + '0'), --top;
        return *this;
    }
    template <typename T>
    typename std::enable_if_t<is_char<T>::value, Writer&> operator<<(const T& c) {
        putchar(c);
        return *this;
    }
    Writer& operator<<(char* str) {
        int cur = 0;
        while (str[cur]) putchar(str[cur++]);
        return *this;
    }
    Writer& operator<<(const char* str) {
        int cur = 0;
        while (str[cur]) putchar(str[cur++]);
        return *this;
    }
    template <typename T1, typename T2>
    Writer& operator<<(const std::pair<T1, T2>& x) {
        *this << x.first << print_between << x.second;
        if (print_T_endl) *this << '\n';
        return *this;
    }
    Writer& operator<<(const std::string& str) {
        int st = 0, ed = str.size();
        while (st < ed) putchar(str[st++]);
        return *this;
    }
    Writer() { }
} cout;
}
}
#define cin FastIO::Fastio::cin
#define cout FastIO::Fastio::cout
#define endl FastIO::Fastio::endl

#define mutil false
int t = 1, id;

void solve(int cas);

signed main() {
#ifndef ONLINE_JUDGE
    freopen(".in.txt", "r", stdin);
#endif
    if (mutil) cin >> t;
    for (int cas = 1; cas <= t; cas++) solve(cas);
    return 0;
}

int n, m, k;
int b[N][N]; // 差分数组
int x[N], y[N]; // 原数组
int nn, mm, tx[N], ty[N]; // 离散化数组
int lx[N], rx[N], ly[N], ry[N]; // k = mid 时候的影响边界
bool check (int mid) { // 判断 k = mid 是否可以
    nn = 0, mm = 0;
    tx[++nn] = 1, tx[++nn] = n;
    ty[++mm] = 1, ty[++mm] = m;
    for (int i = 1; i <= k; i++) {
        lx[i] = max(1LL, x[i] - mid);
        rx[i] = min(n, x[i] + mid);
        ly[i] = max(1LL, y[i] - mid);
        ry[i] = min(m, y[i] + mid);
        tx[++nn] = lx[i], tx[++nn] = rx[i];
        ty[++mm] = ly[i], ty[++mm] = ry[i];
        tx[++nn] = max(1LL, lx[i] - 1), tx[++nn] = min(n, rx[i] + 1);
        ty[++mm] = max(1LL, ly[i] - 1), ty[++mm] = min(m, ry[i] + 1);
    }
    sort (tx + 1, tx + nn + 1); nn = unique(tx + 1, tx + nn + 1) - tx - 1;
    sort (ty + 1, ty + mm + 1); mm = unique(ty + 1, ty + mm + 1) - ty - 1;
    for (int i = 0; i <= nn + 1; i++)
        for (int j = 0; j <= mm + 1; j++)
            b[i][j] = 0;
    for (int i = 1; i <= k; i++) {
        lx[i] = lower_bound (tx + 1, tx + nn + 1, lx[i]) - tx;
        rx[i] = lower_bound (tx + 1, tx + nn + 1, rx[i]) - tx;
        ly[i] = lower_bound (ty + 1, ty + mm + 1, ly[i]) - ty;
        ry[i] = lower_bound (ty + 1, ty + mm + 1, ry[i]) - ty;
    }
    for (int i = 1; i <= k; i++) {
        b[lx[i]][ly[i]]++;
        if (ry[i] < mm) b[lx[i]][ry[i] + 1]--;
        if (rx[i] < nn) b[rx[i] + 1][ly[i]]--;
        if (rx[i] < nn && ry[i] < mm) b[rx[i] + 1][ry[i] + 1]++;
    }
    for (int i = 1; i <= nn; i++) 
        for (int j = 1; j <= mm; j++) {
            b[i][j] += b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1];
        }
    int minx = 1e9, maxx = 0, miny = 1e9, maxy = 0;
    for (int i = 1; i <= nn; i++) 
        for (int j = 1; j <= mm; j++) {
            if (!b[i][j]) {
                minx = min(minx, i);
                miny = min(miny, j);
                maxx = max(maxx, i);
                maxy = max(maxy, j);
            }
        }
    if (!maxx) return true;
    return (max(tx[maxx] - tx[minx] + 1, ty[maxy] - ty[miny] + 1) >> 1) <= mid;
}

void solve(int cas) {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) cin >> x[i] >> y[i];
    int l = 0, r = max(m, n), ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check (mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}
// Start Time =  07:54 AM
// End Time =  
// Submit Times = 1 