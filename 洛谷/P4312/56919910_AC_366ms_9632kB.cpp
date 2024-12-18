#include <bits/stdc++.h>
using std::cout;
using std::swap;
using std::vector;
const int N = 3e4 + 10;
const int Q = 3e5 + 10;
int n, q;
int arr[N];
char c[Q][10];
int in1[Q], in2[Q];
int ans[Q];
int father[N], son[N], top[N], siz[N], id[N], dep[N], rank[N], tot;
int sum[N << 2], l[N << 2], r[N << 2];
vector<int> edge[N];
int fa[N];
int find(int x) {
   return fa[x] == x ? x : find(fa[x]);
}
bool merge(int x, int y) {
   int fx = find(x);
   int fy = find(y);
   if (fx == fy)
      return false;
   fa[fx] = fy;
   return true;
}
void dfs1(int x, int parent) {
   siz[x] = 1;
   dep[x] = dep[parent] + 1;
   father[x] = parent;
   for (int i : edge[x]) {
      if (i != parent) {
         dfs1(i, x);
         siz[x] += siz[i];
         if (siz[i] > siz[son[x]])
            son[x] = i;
      }
   }
}
void dfs2(int x, int parent) {
   top[x] = parent;
   id[x] = ++tot;
   rank[tot] = x;
   if (son[x])
      dfs2(son[x], parent);
   for (int i : edge[x]) {
      if (i != son[x] && i != father[x])
         dfs2(i, i);
   }
}
void build(int o, int L, int R) {
   l[o] = L;
   r[o] = R;
   if (L == R) {
      sum[o] = arr[rank[L]];
      return;
   }
   int mid = (L + R) >> 1;
   build(o << 1, L, mid);
   build(o << 1 | 1, mid + 1, R);
   sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
int query(int o, int L, int R) {
   if (L <= l[o] && r[o] <= R)
      return sum[o];
   int mid = (l[o] + r[o]) >> 1;
   int ans = 0;
   if (L <= mid)
      ans += query(o << 1, L, R);
   if (mid < R)
      ans += query(o << 1 | 1, L, R);
   return ans;
}
void update(int o, int id, int x) {
   if (l[o] == r[o]) {
      sum[o] = x;
      return;
   }
   int mid = (l[o] + r[o]) >> 1;
   if (id <= mid)
      update(o << 1, id, x);
   else
      update(o << 1 | 1, id, x);
   sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
int main() {

#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

   scanf("%d", &n);
   for (int i = 1; i <= n; i++)
      fa[i] = i;
   for (int i = 1; i <= n; i++)
      scanf("%d", &arr[i]);
   scanf("%d", &q);
   for (int i = 1; i <= q; i++)
      scanf("%s%d%d", c[i], &in1[i], &in2[i]);

   for (int i = 1; i <= q; i++)
      if (c[i][0] == 'b')
         if (merge(in1[i], in2[i])) {
            edge[in1[i]].push_back(in2[i]);
            edge[in2[i]].push_back(in1[i]);
         }
   for (int i = 1; i <= n; i++) {
      if (fa[i] == i) {
         dfs1(i, i);
         dfs2(i, i);
      }
   }
   build(1, 1, n);

   for (int i = 1; i <= n; i++)
      fa[i] = i;
   for (int i = 1; i <= q; i++) {
      if (c[i][0] == 'b') {
         if (merge(in1[i], in2[i]))
            puts("yes");
         else
            puts("no");
      } else if (c[i][0] == 'p') {
         update(1, id[in1[i]], in2[i]);
      } else {
         if (find(in1[i]) == find(in2[i])) {
            int res = 0;
            int L = in1[i], R = in2[i];
            while (top[L] != top[R]) {
               if (dep[top[L]] < dep[top[R]])
                  swap(L, R);
               res += query(1, id[top[L]], id[L]);
               L = father[top[L]];
            }
            if (dep[L] > dep[R])
               swap(L, R);
            res += query(1, id[L], id[R]);
            printf("%d\n", res);
         } else {
            puts("impossible");
         }
      }
   }
}