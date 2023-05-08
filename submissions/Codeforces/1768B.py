# iagorrr ;)
t = int(input())
for _ in range(t):
	n, k = map(int, input().split())
	v = list(map(int, input().split()))

	i = 0
	c = 1
	for vi in v:
		if vi == c:
			c += 1
		else:
			i += 1
			
	ans = int(i/k)
	if i%k != 0:
		ans += 1
	print(ans)
# AC
