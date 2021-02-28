n = int(input())
apple = list(map(int, input().split()))
total = sum(apple)
ans = int(1e11)

for i in range(1<<n):
    cur = 0;
    for j in range(n):
        cur += ((i >> j) & 1) * apple[j]
    ans = min(ans, abs(total - cur - cur))

print(ans)
        
