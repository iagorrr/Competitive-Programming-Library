# iagorrr ;)
buff = []

h, a = map(int, input().split())
c = h // a
if h % a != 0:
    c += 1
buff.append(c)
for _ in buff:
    print(_, end="\n")

# AC, ad-hoc, math
