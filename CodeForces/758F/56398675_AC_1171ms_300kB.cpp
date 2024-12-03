// @Author: @qmwneb 
// @Language: C++14 
// @Date: Sun 11/24/2024 
// @Time: 05:47 AM
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e7 + 10;
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

int n, l, r, ans, pw[10100];
int qpow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res *= a;
        a *= a, b >>= 1;
    }
    return res > INT_MAX ? INT_MAX : res;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve(int cas);

signed main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    if (mutil) cin >> t;
    for (int cas = 1; cas <= t; cas++) solve(cas);
    return 0;
}


void solve(int cas) {
    cin >> n >> l >> r;
    if(n > 24) return puts("0"), void();
    if(n == 1) return printf("%d\n", r - l + 1), void();
    if(n == 2) return printf("%lld\n", (r - l + 1ll) * (r - l)), void();
    for(int i = 1; ; i++) if((pw[i] = qpow(i, n - 1)) > r) break;
    for(int p = 1; pw[p] <= r; p++)
        for(int q = 1; pw[q] <= r; q++)
            if(gcd(p, q) == 1 && (p != 1 || q != 1)) {
                int L = max((l + pw[p] - 1) / pw[p], (l + pw[q] - 1) / pw[q]);
                int R = min(r / pw[p], r / pw[q]);
                ans += max(0ll, R - L + 1);
            }
    printf("%d\n", ans);
    return;
}
// Start Time = 05:47 AM
// End Time =  
// Submit Times =  
