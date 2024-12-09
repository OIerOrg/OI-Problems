#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::vector<int> remainders(n);
        for(int i = 0; i < n; i++) {
            remainders[i] = a[i] % k;
        }
        std::vector<int> frequency(k, 0);
        for(int i = 0; i < n; i++) {
            frequency[remainders[i]]++;
        }
        bool possible = false;
        int uniqueRemainder = -1;
        for(int i = 0; i < k; i++) {
            if(frequency[i] == 1) {
                possible = true;
                uniqueRemainder = i;
                break;
            }
        }
        if(possible) {
            for(int i = 0; i < n; i++) {
                if(remainders[i] == uniqueRemainder) {
                    uniqueRemainder = i;
                    break;
                }
            }
            std::cout << "YES" << std::endl;
            std::cout << uniqueRemainder + 1 << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}