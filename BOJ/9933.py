n = int(input())
a = {}
l = []
for i in range(n):
    s = input()
    a[s] = 1;
    s = s[::-1]
    if s in a:
        print(str(len(s)) + ' ' + s[len(s)//2])
