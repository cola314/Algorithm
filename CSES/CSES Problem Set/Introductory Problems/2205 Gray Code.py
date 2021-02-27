n = int(input())
for i in range(1<<n):
    t = i & (1<<n-1);
    for j in range(1, n):
        t |= (((i >> j) ^ (i >> j-1)) & 1) << j - 1;

    for j in range(n-1, -1, -1):
        print((t >> j) & 1, end = '')
    print()
