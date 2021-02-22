t = int(input())
for i in range(t):
    y, x = map(int, input().split())
    n = max(y, x)
    if n % 2 == 0 and x < n or n % 2 == 1 and y < n:
        print(n*n-n+1 + n-x + n-y)
    else:
        print(n*n-n+1 - (n-x) - (n-y))
