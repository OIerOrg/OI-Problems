#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;

    auto countOnes = [&](i64 num) {
        i64 cnt = 0;
        for (i64 k = 1; k <= num; k *= 10) {
            i64 high = num / (k * 10);
            i64 cur = (num / k) % 10;
            i64 low = num % k;
            
            if (cur > 1) {
                cnt += (high + 1) * k;
            } else if (cur == 1) {
                cnt += high * k + (low + 1);
            } else {
                cnt += high * k;
            }
        }
        return cnt;
    };

    std::cout << countOnes(n) << "\n";
    
    return 0;
}
