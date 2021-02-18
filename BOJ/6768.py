n = int(input())
ans = 0
for a in range(1, n):
    for b in range(a+1, n):
        for c in range(b+1, n):
            ans = ans + 1;

print(ans)
