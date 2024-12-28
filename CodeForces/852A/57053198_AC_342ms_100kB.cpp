#include <bits/stdc++.h>

using i64 = long long;

int main() {
#ifndef ONLINE_JUDGE
    assert(freopen(".in.txt", "r", stdin));
    assert(freopen(".out.txt", "w", stdout));
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    constexpr int maxSteps = 3;
    std::vector<std::string> results(maxSteps);

    auto calculateSum = [](const std::string& str) -> int {
        int sum = 0, num = 0;
        for (char c : str) {
            if (c == '+') {
                sum += num;
                num = 0;
            } else {
                num = num * 10 + (c - '0');
            }
        }
        return sum + num;
    };

    srand(time(nullptr));
    std::string t;
    do {
        t = s;
        for (int step = 0; step < maxSteps; ++step) {
            std::string temp;
            for (int i = 0; i < t.size(); ++i) {
                if (i > 0 && rand() % 100 > 5) {
                    temp.push_back('+');
                }
                temp.push_back(t[i]);
            }
            results[step] = temp;
            int sum = calculateSum(temp);

            t.clear();
            while (sum > 0) {
                t.push_back('0' + (sum % 10));
                sum /= 10;
            }
            std::reverse(t.begin(), t.end());
        }
    } while (t.size() != 1);

    for (const auto& res : results) {
        std::cout << res << '\n';
    }

    return 0;
}