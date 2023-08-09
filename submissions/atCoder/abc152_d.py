# iagorrr ;)

n = int(input())

cnt = []
for i in range(0, 10 + 1):
    cnt.append([])
    for j in range(0, 10 + 1):
        cnt[i].append(0)


for i in range(1, n + 1):
    l = int(str(i)[0])
    r = int(str(i)[-1])
    cnt[l][r] += 1


ans = 0
mod = 1e9 + 7
for i in range(0, 10 + 1):
    for j in range(0, 10 + 1):
        ans = int((ans + int(cnt[i][j] * cnt[j][i])) % mod)

print(ans)

# AC, math, brute force
