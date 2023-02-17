# iagorrr ;)
from itertools import combinations
m, n = map(int, input().split())
l = sorted([input().split() for _ in range(m)])
ans = list()
for c in combinations(l, n): # l tomado n a n.
    cc = sum(x == 'F' for y, x in c)
    if cc > 1 and cc < n-1:
        ans.append(c)

print(len(ans))
for s in ans:
    print(','.join(x[0] for x in s))
