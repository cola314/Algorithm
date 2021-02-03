n = int(input())
ans = 0
a = 1
k = 9

while n > k:
    ans += a * k
    n -= k
    a+=1
    k*=10

ans += a * n
print(ans)