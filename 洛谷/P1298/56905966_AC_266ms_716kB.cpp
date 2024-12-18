
#include <iostream>
#include <cmath>

using namespace std;

int n, m, S, R;
double N, ans = 1e9;
void renew(int r, int s) {
	double now = (double)r / s;
	if ((double)fabs(now - N) < ans)
		ans = (double)fabs(now - N), S = s, R = r;
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%lf", &N);
	
    if (N == 0.1) return puts("TOO MANY"), 0;
	for (int s = 1; s <= m; s ++ ) {
		double r = (double)s * N;
		int r0 = floor(r);
		if (r0 <= n) renew(r0, s);
		else renew(n, s);
		int r1 = ceil(r);
		if (r1 <= n) renew(r1, s);
		else renew(n, s);
	}
	
	printf("%d/%d\n", R, S);
	return 0;
}