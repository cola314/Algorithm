input()
pre = -1
ans = 0
for n in map(int, input().split()):
    if pre != -1 and pre > n:
        ans += pre - n
    else:
        pre = n
print(ans)
