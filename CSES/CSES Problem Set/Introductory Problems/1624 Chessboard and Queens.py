checked = list()
ans = 0

for i in range(8):
    checked.append(input())

def f(idx, dt):
    global ans
    if idx == 8:
        ans += 1
        return
    for i in range(8):
        if checked[idx][i] == '*':
            continue
        
        dt[idx] = i
        if can(idx, dt):
            f(idx + 1, dt)

def can(idx, dt):
    for i in range(idx):
        if dt[idx] == dt[i]:
            return False

    for i in range(idx):
        if dt[idx] - idx == dt[i] - i:
            return False

    for i in range(idx):
        if dt[idx] + idx == dt[i] + i:
            return False

    return True

f(0, [0]*8)
print(ans)
