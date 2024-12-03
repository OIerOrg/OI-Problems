#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

bool check (int i, int a, int b, int c, int d, int e, int f, std::vector <int> arr) {
	return arr[i + a] + arr[i + b] > arr[i + c] && arr[i + d] + arr[i + e] > arr[i + f];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector <int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    while (q--) {
    	int l, r;
    	std::cin >> l >> r;
    	if (r - l + 1 >= 50) {
    		std::cout << "YES\n";
    		continue;
    	}
    	std::vector <int> b(a.begin() + l - 1, a.begin() + r);
    	std::sort (b.begin(), b.end());

    	bool ok = false;
    	int L = 1e9, R = -1;
    	for (int i = 0; i + 2 < b.size(); i++) {
    		if (b[i] + b[i + 1] > b[i + 2]) {
    			L = std::min(L, i);
    			R = i;
    		}
    	}
    	if (R - L >= 3) {
    		ok = true;
    	}
    	for (int i = 0; i + 5 < b.size() && !ok; i++) {
    		if (check(i, 0, 1, 3, 2, 4, 5, b)) {
    			ok = true;
    			break;
    		}
    		if (check(i, 0, 1, 4, 2, 3, 5, b)) {
    			ok = true;
    			break;
    		}
    		if (check(i, 0, 1, 5, 2, 3, 4, b)) {
    			ok = true;
    			break;
    		}
    		if (check(i, 0, 2, 3, 1, 4, 5, b)) {
    			ok = true;
    			break;
    		}
    		if (check(i, 0, 2, 4, 1, 3, 5, b)) {
    			ok = true;
    			break;
    		}
    		if (check(i, 0, 2, 5, 1, 3, 4, b)) {
    			ok = true;
    			break;
    		}
    		if (check(i, 0, 3, 4, 1, 2, 5, b)) {
    			ok = true;
    			break;
    		}
    		if (check(i, 0, 3, 5, 1, 2, 4, b)) {
    			ok = true;
    			break;
    		}
    		if (check(i, 0, 4, 5, 1, 2, 3, b)) {
    			ok = true;
    			break;
    		}
    	}
    	if (ok) {
    		std::cout << "YES\n";
    	} else {
    		std::cout << "NO\n";
    	}
    }
    return 0;
}