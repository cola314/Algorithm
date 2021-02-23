ans=0
cur=5
n = int(input())
while n >= cur:
    ans += n // cur
    cur *= 5
print(ans)
