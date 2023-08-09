# iagorrr ;)

n = int(input())
p = list(map(int, input().split()))
ans = 0
cm = p[0]
for i in range(0, len(p)):
    cm = min(cm, p[i])
    if p[i] <= cm:
        ans += 1
print(ans)

# AC, ad-hoc, greedy
