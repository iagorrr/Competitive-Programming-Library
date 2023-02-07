# iagorrr ;)
n, q = map(int, input().split())

x = list(map(int, input().split()))

psum = [0]

for xx in x:
    psum.append(psum[-1]+xx)

for _ in range(q):
    a, b = map(int, input().split())
    print(psum[b]-psum[a-1])

# AC.

