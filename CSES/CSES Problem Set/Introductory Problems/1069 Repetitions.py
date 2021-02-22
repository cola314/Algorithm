ans = cur = 0
s = input()
for i in range(len(s)):
    if i != 0 and s[i] == s[i-1]:
        cur += 1
    else:
        cur = 1
    ans = max(ans, cur)
print(ans)
