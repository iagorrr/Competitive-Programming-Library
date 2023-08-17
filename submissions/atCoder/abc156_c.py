# iagorrr ;)
buff = []
n = map(int, input().split())
xs = list(map(int, input().split()))

ans = 10000000000
for i in range(1, 100 + 1):
    ansc = 0
    for xi in xs:
        ansc += (xi - i) ** 2
    ans = min(ans, ansc)

buff.append(ans)
for _ in buff:
    print(_)

# AC, math, brute force
