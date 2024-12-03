#include <bits/stdc++.h>
using namespace std;
int t;
int n, a, b, x, y;
void solve() {
	cin >> n >> a >> b;
	x = y = 0;
	string s;
	cin >> s;
	for (int i = 0; i < n * 1000; i++) {
		if (s[i % n] == 'N') y++;
		if (s[i % n] == 'E') x++;
		if (s[i % n] == 'S') y--;
		if (s[i % n] == 'W') x--;
		if (x == a && y == b) {
			return puts("YES"), void();
		}
	}
	puts("NO");
}
int main() {
	cin >> t;
	while (t--) {
		solve();
	}
}