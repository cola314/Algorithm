n, m = map(int, input().split())
box = list(range(n))
for i in range(m):
    a, b = map(int, input().split())
    box[a-1], box[b-1] = box[b-1], box[a-1]

for e in box:
    print(e + 1, end=' ')