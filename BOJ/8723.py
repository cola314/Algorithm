l = list(map(int,input().split()))
l.sort()
a,b,c=map(int, l)
if a==b==c:
    print(2)
elif a*a+b*b==c*c:
    print(1)
else:
    print(0)
