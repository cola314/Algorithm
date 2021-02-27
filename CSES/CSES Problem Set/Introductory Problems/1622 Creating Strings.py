s = input()
n = len(s)
cur = [0]*n
ans = {}
def f(idx):
    if idx == n:
        t = ""
        for c in cur:
            t += c
        ans[t] = 1
    for i in range(n):
        if cur[i] == 0:
            cur[i] = s[idx]
            f(idx + 1)
            cur[i] = 0

f(0)
ans = list(ans);
ans.sort()
print(len(ans))
for a in ans:
    print(a)
