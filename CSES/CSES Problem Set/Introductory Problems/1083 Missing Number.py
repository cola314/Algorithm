n = int(input())
ans = 0
for t in map(int, input().split()):
    ans ^= t

for i in range(1, n+1):
    ans ^= i

print(ans)
    
