#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
const int N = 100005;
ll n, k, a[N], st[N][20], lg_table[N];

inline ll pushup(ll x, ll y) {
	return a[x] > a[y] ? x : y;
}

inline ll getmax(ll l, ll r) {
	ll d = lg_table[r - l + 1];
	return pushup(st[l][d], st[r - (1 << d) + 1][d]);
}

ll solve(ll l, ll r, ll d) {
	if (l > r) return 0;
	ll mid = getmax(l, r);
	if (a[mid] % d == 0) return solve(l, mid - 1, d) + 1 + solve(mid + 1, r, d);
	ll ans = 0;
	if (1 < l) ans = std::max(ans, solve(mid + 1, r, d));
	if (r < n) ans = std::max(ans, solve(l, mid - 1, d));
	return ans;
}

std::vector<ll> getDivisors(ll x) {
	std::vector<ll> divisors;
	for (ll i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			divisors.emplace_back(i);
			if (x / i != i) {
				divisors.emplace_back(x / i);
			}
		}
	}
	std::sort(divisors.begin(), divisors.end(), std::greater<ll>());
	return divisors;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> n >> k;
	lg_table[1] = 0;
	for (ll i = 2; i <= n; ++i)
		lg_table[i] = lg_table[i >> 1] + 1;
	for (ll i = 1; i <= n; ++i) {
		std::cin >> a[i];
		st[i][0] = i;
	}
	for (ll j = 1; (1 << j) <= n; ++j) {
		for (ll i = 1; i + (1 << j) - 1 <= n; ++i) {
			st[i][j] = pushup(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	ll max_idx = getmax(1, n);
	ll x = a[max_idx];
	auto divisors = getDivisors(x);
	for (auto d : divisors) {
		if (solve(1, n, d) >= k) {
			std::cout << d << "\n";
			return 0;
		}
	}
	std::cout << "0";
	return 0;
}
