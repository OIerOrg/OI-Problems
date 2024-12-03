#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int Mod = 998244353;
int n, m, ans = 1;
char a[N], b[N];
int cnta[30], cntb[30];
int fac[N], inv[N];
int f[30][N], g[30][N];
int qpow(int a, int b) {
    int ans = 1;
    for (; b; b >>= 1, a = 1ll * a * a % Mod)
        if (b & 1) ans = 1ll * ans * a % Mod;
    return ans;
}
int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % Mod * inv[n - m] % Mod;
}
int main() {
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1);
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % Mod;
    for (int i = 0; i < N; i++) inv[i] = qpow(fac[i], Mod - 2);
    for (int i = 1; i <= n; i++) cnta[a[i] - 'A' + 1]++;
    for (int i = 1; i <= m; i++) cntb[b[i] - 'A' + 1]++;
    f[0][0] = 1;
    for (int j = 0; j <= cntb[1]; j++) g[0][j] = 1;
    for (int i = 1; i <= 26; i++) {
        for (int j = max(0, cnta[i] - cntb[i]); j <= min(cnta[i], cntb[i + 1]); j++) {
            f[i][j] = 1ll * g[i - 1][cntb[i] - cnta[i] + j] * C(cnta[i], j) % Mod;
        }
        g[i][0] = f[i][0];
        for (int j = 1; j <= cntb[i + 1]; j++) g[i][j] = (g[i][j - 1] + f[i][j]) % Mod;
        ans = 1ll * ans * inv[cnta[i]] % Mod;
    }
    printf("%d\n", 1ll * g[26][0] * ans % Mod * fac[n] % Mod);
    return 0;
}