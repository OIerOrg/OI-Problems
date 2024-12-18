n = int(input())
ans = 0
while (n != 1):
    n = n // 2
    ans = ans + 1
print(ans + 1)