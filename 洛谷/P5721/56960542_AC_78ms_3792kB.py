n = int(input())
cnt = 1
for i in range(1, n + 1):  # 控制每一行
    for j in range(1, n - i + 2):  # 每行的数字数量
        if cnt < 10:
            print(f"0{cnt}", end="")
        else:
            print(cnt, end="")
        cnt += 1
    print()  # 换行
