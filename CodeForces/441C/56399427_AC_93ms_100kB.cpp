#include<bits/stdc++.h>
using namespace std;
int n, m, k;
struct grid {
	int x, y;
};
void move(grid &cur) {
	if (cur.x % 2 == 1) {
		if (cur.y == m)++cur.x;
		else ++cur.y;
	} else {
		if (cur.y == 1)++cur.x;
		else --cur.y;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	grid a = (grid) {
		1, 1
	};
	for (int i = 1; i < k; i++) {
		printf("2 ");
		printf("%d %d ", a.x, a.y);
		move(a);
		printf("%d %d\n", a.x, a.y);
		move(a);
	}
	printf("%d ", n * m - 2 * (k - 1));
	for (int i = 1; i <= n * m - 2 * (k - 1); i++)
		printf("%d %d ", a.x, a.y), move(a);
	return 0;
}