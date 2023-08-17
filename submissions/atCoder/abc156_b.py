# iagorrr ;)
buff = []

n, k = map(int, input().split())
a = ""
while n > 0:
    a += str(n % k)
    n //= k

buff.append(len(a))
for _ in buff:
    print(_)

# AC, math
