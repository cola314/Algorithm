n = int(input())
l = []
ans = 0

for i in range(n):
    l.append(int(input()))

l.reverse()

for i in range(1, n):
    if l[i-1] <= l[i]:
        ans, l[i] = ans + l[i] - l[i-1] + 1, l[i-1] - 1

print(ans)