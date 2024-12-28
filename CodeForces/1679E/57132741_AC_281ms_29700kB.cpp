#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 mod = 998244353;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::string s, t;
    std::cin >> n >> s >> q;
    s = " " + s;
    std::vector<int> qcnt(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        qcnt[i] = qcnt[i - 1] + (s[i] == '?');
    }
    std::vector<std::vector<bool>> zero(n + 1, std::vector<bool>(n + 1, false));
    std::vector<std::vector<int>> inc(n + 1, std::vector<int>(n + 1, 0));
    std::vector<std::vector<int>> plen(n + 1, std::vector<int>(n + 1, 0));
    std::vector<std::vector<i64>> pw(18, std::vector<i64>(n + 1, 0));
    for (int k = 1; k <= 17; ++k) {
        pw[k][0] = 1;
        for (int i = 1; i <= n; ++i) {
            pw[k][i] = pw[k][i - 1] * k % mod;
        }
    }
    std::vector<std::vector<i64>> val((1 << 17), std::vector<i64>(18, 0));
    for (int len = 1; len <= n; ++len) {                              
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            if (len == 1) {
                if (s[i] == '?') {
                    plen[i][j] = 1;
                }
            } else {
                if (zero[i + 1][j - 1]) {
                    zero[i][j] = true;
                } else {
                    if (s[i] == '?' && s[j] == '?') {
                        inc[i][j] = inc[i + 1][j - 1];
                        plen[i][j] = plen[i + 1][j - 1] + 1;
                    }
                    else if (s[i] == '?') {
                        inc[i][j] = inc[i + 1][j - 1] | (1 << (s[j] - 'a'));
                        plen[i][j] = plen[i + 1][j - 1];
                    }
                    else if (s[j] == '?') {
                        inc[i][j] = inc[i + 1][j - 1] | (1 << (s[i] - 'a'));
                        plen[i][j] = plen[i + 1][j - 1];
                    }
                    else if (s[i] == s[j]) {
                        inc[i][j] = inc[i + 1][j - 1];
                        plen[i][j] = plen[i + 1][j - 1];
                    }
                    else {
                        zero[i][j] = true;
                    }
                }
            }

            if (!zero[i][j]) {
                int power_val = plen[i][j] + qcnt[n] - (qcnt[j] - qcnt[i - 1]);
                if(power_val >= 0 && power_val <= n){
                    for (int k = 1; k <= 17; ++k){
                        val[inc[i][j]][k] += pw[k][power_val];
                        val[inc[i][j]][k] %= mod;
                    }
                }
            }
        }
    }
    for (int i_bit = 0; i_bit < 17; ++i_bit){
        for(int mask = 0; mask < (1 << 17); mask++){
            if((mask >> i_bit) & 1) {
                for(int k = 1; k <= 17; ++k){
                    val[mask][k] += val[mask ^ (1 << i_bit)][k];
                    val[mask][k] %= mod;
                }
            }
        }
    }
    while(q--){
        std::cin >> t;
        int query_mask = 0;
        for(char c: t){
            query_mask |= 1 << (c - 'a');
        }
        int t_size = t.size();
        if(t_size >= val[query_mask].size()){
            std::cout << "0\n";
        }
        else{
            std::cout << val[query_mask][t_size] << "\n";
        }
    }

    return 0;
}