s=input()
cnt = {}
for c in s:
    if c in cnt.keys(): cnt[c]+=1
    else: cnt[c] = 1

pre = ''
for i in range(ord('A'),ord('Z')+1):
    if chr(i) in cnt.keys() and cnt[chr(i)] % 2 == 1:
        if pre != '':
            print("NO SOLUTION")
            exit(0)
        else: pre = chr(i)

for i in range(ord('A'),ord('Z')+1):
    if chr(i) in cnt.keys() and cnt[chr(i)] % 2 == 0:
        for j in range(cnt[chr(i)]//2):
            print(chr(i),end='')

if pre != '':
    for i in range(cnt[pre]):
        print(pre,end='')

for i in range(ord('Z'),ord('A')-1,-1):
    if chr(i) in cnt.keys() and cnt[chr(i)] % 2 == 0:
        for j in range(cnt[chr(i)]//2):
            print(chr(i),end='')
        
