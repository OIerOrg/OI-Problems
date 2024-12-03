#include <iostream>

using namespace std;

int ask(int i) {
	cout << "? " << i << endl;
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n, k;
	cin >> n >> k;
	int res = 0;
	int i;
	for (i = 1; n - i + 1 >= 2 * k; i += k)
		res ^= ask(i);
	if (n - i + 1 == k) {
		res ^= ask(i);
		cout << "! " << res << endl;
		return;
	}
	int y = (n - i + 1 - k) / 2;
	res ^= ask(i);
	res ^= ask(i + y);
	res ^= ask(i + 2 * y);
	cout << "! " << res << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}