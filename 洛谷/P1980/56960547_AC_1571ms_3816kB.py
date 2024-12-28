n, x = map(int, input().split())
x = str(x)
count = 0
for i in range(1, n + 1):
    count += str(i).count(x)
print (count)