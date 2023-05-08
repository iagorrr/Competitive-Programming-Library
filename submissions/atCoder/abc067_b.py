# iagorrr ;)
n, k = map(int, input().split())
l = list(map(int, input().split()))
l.sort(reverse=True)
print(sum(l[0:k]))
# AC.
