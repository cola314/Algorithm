for i in range(int(input())):
    a,b=map(int,input().split())
    print('YES' if (a+b)%3==0 and (2*b-a)>=0 and (2*b-a)%3==0 and (2*a-b)>=0 and (2*a-b)%3==0 else 'NO')
