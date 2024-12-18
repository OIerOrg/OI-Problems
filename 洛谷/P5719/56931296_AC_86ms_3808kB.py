[n, k] = [int(_) for _ in input().split()]
cnt1 = sum1 = cnt2 = sum2 = 0

for i in range(1, n + 1):
    if i % k == 0:  # 判断是否为 k 的倍数
        cnt1 += 1
        sum1 += i
    else:
        cnt2 += 1
        sum2 += i

# 使用 f-string 保留一位小数
print(f"{sum1 / cnt1:.1f} {sum2 / cnt2:.1f}")
