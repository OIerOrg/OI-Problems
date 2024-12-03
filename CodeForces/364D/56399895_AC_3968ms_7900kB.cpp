#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int arr[1000005];

vector<int> get_divisors(int x) {
	vector<int> ans;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			ans.push_back(i);
			if (x / i != i)
				ans.push_back(x / i);
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(NULL)); 
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int ans = 0, t = 12;

	while (t--) {
		int rand_pos = rand() * rand() % n + 1;
		vector<int> d = get_divisors(arr[rand_pos]);
		sort(d.begin(), d.end());
		int siz = d.size();
		vector<int> cnt(siz, 0);

		// 统计每个因子的出现次数
		for (int i = 1; i <= n; i++) {
			int g = gcd(arr[rand_pos], arr[i]);
			// 使用 lower_bound 查找 gcd 值在 d 中的位置
			int idx = lower_bound(d.begin(), d.end(), g) - d.begin();
			if (idx < siz && d[idx] == g) {
				cnt[idx]++;
			}
		}

		// 累加因子的倍数出现次数
		for (int i = 0; i < siz; i++) {
			for (int j = i + 1; j < siz; j++) {
				if (d[j] % d[i] == 0) {
					cnt[i] += cnt[j];
				}
			}
		}

		// 找到第一个满足 cnt[i] * 2 >= n 的最大因子
		for (int i = siz - 1; i >= 0; i--) {
			if (cnt[i] * 2 >= n) {
				ans = max(ans, d[i]);
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
