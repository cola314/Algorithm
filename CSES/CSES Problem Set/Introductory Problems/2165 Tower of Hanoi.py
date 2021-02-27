def f(n, s, e, m):
    if n == 1:
        print("%d %d"%(s, e))
        return
    f(n-1, s, m, e)
    f(1, s, e, m)
    f(n-1, m, e, s)

n = int(input())
print((1<<n)-1)
f(n, 1, 3, 2)
