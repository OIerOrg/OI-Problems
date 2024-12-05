#include <bits/stdc++.h>

int t, n, a[1005], f[1005];
int main() {
#ifndef ONLINE_JUDGE
    assert(freopen("in.txt", "r", stdin));
    assert(freopen("out.txt", "w", stdout));
#endif

    std::cin >> t;

    while (t--) {
        memset(f, 0x3f, sizeof f);
        std::cin >> n;

        for (int i = 1; i <= n; i++)
            std::cin >> a[i];

        f[0] = 0;

        for (int i = 1, k, minn; i <= n; i++) {
            for (int j = std::max(i - a[i] + 1, 0); j <= i; j++)
                f[i] = std::min(f[i], f[j - 1] + 1);

            for (int j = 1; j < i; j++)
                if (j + a[j] - 1 >= i)
                    f[i] = std::min(f[i], f[j - 1] + 1);

            k = i - 1, minn = f[i - 1];

            for (int j = i + 1; j <= std::min(i + a[i] - 1, n); j++) {
                while (k > std::max(j - a[j], 0))
                    minn = std::min(minn, f[--k]);

                f[j] = std::min(f[j], minn + 2);
            }
        }

        std::cout << f[n] << '\n';
    }

    return 0;
}