#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 998244353;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    // 定义动态规划数组
    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
    int res = 0;

    // 初始化长度为 1 的子串
    for (int i = 1; i <= n; ++i) {
        if (i > m || s[0] == t[i - 1]) {
            f[i][i] = 2;
        }
    }

    // 计算长度为 2 到 n 的子串
    for (int length = 2; length <= n; ++length) {
        for (int i = 1; i <= n - length + 1; ++i) {
            int j = i + length - 1;
            if (i > m || s[length - 1] == t[i - 1]) {
                f[i][j] = (f[i][j] + f[i + 1][j]) % MOD;
            }
            if (j > m || s[length - 1] == t[j - 1]) {
                f[i][j] = (f[i][j] + f[i][j - 1]) % MOD;
            }
        }
    }

    // 计算结果
    for (int i = m; i <= n; ++i) {
        res = (res + f[1][i]) % MOD;
    }

    cout << res << endl;

    return 0;
}
