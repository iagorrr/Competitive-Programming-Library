# iagorrr ;)
n = int(input())
a = list(map(int, input().split()))

l = 0
r = 0

pl = 0
pr = len(a)-1

for _ in range(0, n):
    if a[pl] > a[pr]:
        v = a[pl]
        pl += 1 
    else:
        v = a[pr]
        pr -= 1

    if _%2:
        r += v
    else:
        l += v

    if pl > pr: 
        break

print(f"{l} {r}")

# AC.
