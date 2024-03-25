n, k = map(int, input().split())

l = set(map(int, input().split()))

ans = (k * (k+1)) // 2

for li in l:
	if li <= k:
		ans -= li

print(ans)

