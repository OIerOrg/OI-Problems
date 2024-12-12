#include <cstdio>
#include <algorithm>

const int maxT = 4000105;

int n, m, t, ti, ans = 1e9, cnt[maxT], sum[maxT], f[maxT];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ti); t = std::max(t, ti);
        cnt[ti]++; sum[ti] += ti;
    }
    for (int i = 1; i < t + m; i++) { cnt[i] += cnt[i - 1]; sum[i] += sum[i - 1]; } // 前缀和.
    for (int i = 0; i < t + m; i++) {
        f[i] = cnt[i] * i - sum[i]; // 特判边界情况.
        for (int j = std::max(0, i - 2 * m); j <= i - m; j++) { f[i] = std::min(f[i], f[j] + (cnt[i] - cnt[j]) * i - (sum[i] - sum[j])); }
    }
    for (int i = t; i < t + m; i++) { ans = std::min(ans, f[i]); }
    printf("%d\n", ans);
    return 0;
}