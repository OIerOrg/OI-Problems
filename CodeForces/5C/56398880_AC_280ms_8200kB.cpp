#include <bits/stdc++.h>
using namespace std;
namespace Std {
#define fi first
#define se second
#define db double
#define int long long
#define End puts("");
#define Space putchar(' ');
#define pii pair <int, int>
#define piii pair <int, pii>
#define debug(x) cout << #x << " = " << x;
	const int Mod = 998244353;
	const int mod = 1e9 + 7;
	int fac[100005] = { 1 };
	inline int read();
	inline void write (int x);
	void fac_init (int mod = LLONG_MAX);
	inline int qpow (int x, int y, int mod);
	int contrary (int x, int mod = LLONG_MAX);
	int C (int x, int y, int mod = LLONG_MAX);
	int gcd (int x, int y);
	int lcm (int x, int y);
	//=====================================================================================
	int gcd (int x, int y) {return __gcd (x, y);}
	int lcm (int x, int y) {return x * y / __gcd (x, y);}
	int contrary (int x, int mod) {	return qpow (x, mod - 2, mod);}
	void fac_init (int mod) {for (int i = 1; i <= 100000; i++) { fac[i] = fac[i - 1] * i % mod; }}
	int C (int x, int y, int mod) {return fac[x] * contrary (fac[y], Mod) % mod * contrary (fac[x - y], Mod) % mod;}
	inline int qpow (int x, int y, int mod = LLONG_MAX) {
		if (y == 0) {return 1;}
		if (y == 1) {return x;}
		int t = qpow (x, y >> 1, mod);
		if (y & 1) {return t * t % mod * x % mod;}
		else {return t * t % mod;}
	}
	inline int read() {
		int x = 0, f = 1;
		char ch = getchar();
		while (ch < '0' || ch > '9') {
			if (ch == '-') { f = -1;}
			ch = getchar();
		}
		while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0', ch = getchar();}
		return x * f;
	}
	inline void write (int x) {
		if (x < 0) {putchar ('-'), x = -x;}
		if (x > 9) {write (x / 10);}
		putchar (x % 10 + '0');
		return;
	}
}
using namespace Std;
//==============================================================================================================
//==============================================================================================================
//==================================================main=begin==================================================
//==============================================================================================================
//==============================================================================================================
namespace Work {
	int n, cnt, ans, tot;
	bool a[1001003];
	string s;
	stack <int> S;
	void work() {
		cin >> s;
		n = s.size();
		s = " " + s;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '(') { S.push (i); }
			else if (S.size() ) { a[S.top()] = true; a[i] = true; S.pop(); }
		}
//		for (int i = 1; i <= n; i++) { debug (i); Space; debug (a[i]); End; }
		for (int i = 1; i <= n + 1; i++)
			if (a[i]) { cnt++; }
			else {ans = max (cnt, ans); cnt = 0;}
		for (int i = 1; i <= n + 1; i++)
			if (a[i]) { cnt++; }
			else { if (cnt == ans) tot++; cnt = 0;}
		if (ans) { write (ans); Space; write (tot); End; }
		else { puts ("0 1"); }
		return;
	}
}
//==============================================================================================================
//==============================================================================================================
//===================================================main=end===================================================
//==============================================================================================================
//==============================================================================================================
signed main() {
	//	for (int t = read(); t--;)
	Work::work();
}