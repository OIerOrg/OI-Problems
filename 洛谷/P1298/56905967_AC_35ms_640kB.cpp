#include <algorithm>
#include <cstdio>

using PII = std::pair<int, int>;
double N, m_error;
int n, m;
PII ans(0, 1);
bool flag = false;

double fabs(double x) {
    return x < 0 ? -x : x;
}
inline void get(double N, int a = 0, int b = 1, int c = 1, int d = 0) {
	int x = a + c, y = b + d;
	if (x > n || y > m) return;
	double error = (double)x / y - N;
	if (fabs(error) == m_error) flag = true;
	if (fabs(error) < m_error) {
		flag = false; ans = {x, y}; m_error = fabs(error);
		if (error == 0) return;
	}
	if (error < 0) get(N, x, y, c, d);
	else get(N, a, b, x, y);
}

int main() {
	scanf("%d%d", &n, &m);
	scanf("%lf", &N); m_error = N; get(N);
	if (flag) puts("TOO MANY");
	else printf("%d/%d", ans.first, ans.second);
	return 0;
}