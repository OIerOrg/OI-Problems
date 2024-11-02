#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
int n, m, l, cnt, tmp;
bool x[N], c[N];
int ans[25][N];
int a[N], f[N];
int id[N], cst[25][25];  // 差分数组; 差分数组中第 i 个 1，所在的下标; 抵消 i - j 的最小代价
int main() {
   scanf("%d%d%d", &n, &m, &l);
   for (int i = 1; i <= m; i++)
      scanf("%d", &tmp), x[tmp] = true;
   for (int i = 1; i <= l; i++)
      scanf("%d", a + i);
   for (int i = 0; i <= n; i++)
      c[i] = x[i + 1] ^ x[i];
   for (int i = 0; i <= n; i++)
      if (c[i])
         id[cnt++] = i;
   for (int i = 0; i < cnt; i++) {
      queue<int> q;
      q.push(id[i]);
      ans[i][id[i]] = 1;
      while (q.size()) {
         int top = q.front();
         q.pop();
         for (int j = 1; j <= l; j++) {
            if (0 <= top - a[j] && !ans[i][top - a[j]]) {
               ans[i][top - a[j]] = ans[i][top] + 1;
               q.push(top - a[j]);
            }
            if (top + a[j] <= n && !ans[i][top + a[j]]) {
               ans[i][top + a[j]] = ans[i][top] + 1;
               q.push(top + a[j]);
            }
         }
      }
      for (int j = 0; j < cnt; j++)
         cst[i][j] = ans[i][id[j]] ? ans[i][id[j]] - 1 : 1e9;
   }
   for (int i = 1; i < (1 << cnt); i++)
      f[i] = 1e9;
   for (int i = 0; i < (1 << cnt); i++) {
      int x = 0;
      while ((i >> x) & 1)
         x++;
      for (int y = x + 1; y < cnt; y++) {
         if (((i >> y) & 1) == 0) {
            int nxt = i | (1 << x) | (1 << y);
            f[nxt] = min(f[nxt], f[i] + cst[x][y]);
         }
      }
   }
   if (f[((1 << cnt) - 1)] == 1e9)
      printf("-1");
   else
      printf("%d", f[(1 << cnt) - 1]);
}