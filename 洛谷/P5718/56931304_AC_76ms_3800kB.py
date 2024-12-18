n = int(input())  # 读取 n
a = list(map(int, input().split()))  # 读取一行数字，并转换成整数列表
ans = 10**9  # 设一个大值

for i in range(n):
    ans = min(ans, a[i])  # 遍历列表，取最小值

print(ans)  # 输出结果
