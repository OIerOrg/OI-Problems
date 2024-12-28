n = int(input())
S = 0
fact = 1 
for i in range(1, n + 1):
    fact *= i
    S += fact

print(S)
