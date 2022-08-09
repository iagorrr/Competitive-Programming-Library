# iagorrr ;) O(N)
S = (100, 50, 25, 10, 5, 1)

V = int(input())

ans = 0

for s in S:

    while s <= V:
        V -= s
        ans += 1

print(ans)

# AC