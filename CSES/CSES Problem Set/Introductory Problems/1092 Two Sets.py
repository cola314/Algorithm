n = int(input())
if n%4==0:
    print("YES")
    print(n//2)
    for i in range(1, n//2+1, 2):
        print("%d %d"%(i, n-i+1),end=' ')
    print()
    print(n//2)
    for i in range(2, n//2+1, 2):
        print("%d %d"%(i, n-i+1),end=' ')
elif (n+1)%4==0:
    print("YES")
    print(n//2+1)
    print("1 2",end=' ')
    for i in range(1, (n-3)//2+1, 2):
        print("%d %d"%(i+3, n-i+1),end=' ')
    print()
    print(n//2)
    print("3",end=' ')
    for i in range(2, (n-3)//2+1, 2):
        print("%d %d"%(i+3, n-i+1),end=' ')
else: print("NO")
