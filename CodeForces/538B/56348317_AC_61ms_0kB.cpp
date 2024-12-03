#include <cstdio>
#include <iostream>
using namespace std;

int Ans, num[100];

int main() {
    int n, Res;
    scanf("%d", &n);
    for (int bit = 1; bit <= n; bit *= 10) {
        Res = (n / bit) % 10;
        Ans = max(Ans, Res);
        for (int i = 1; i <= Res; ++i) num[i] += bit;
    }
    printf("%d\n", Ans);
    for (; Ans; --Ans) printf("%d ", num[Ans]);
    putchar('\n');
    return 0;
}