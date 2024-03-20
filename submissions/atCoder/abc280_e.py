mod = 998244353

maxn = 2*10**5 + 66 

n, p = map(int, input().split())
denom = pow(100,mod-2,mod)
ans = [1 for i in range(0, maxn)]
for i in range(1, n+1):
	ans[i + 1] = (ans[i+1] + ans[i] * (100-p) * denom) % mod
	ans[i + 2] = (ans[i+2] + ans[i] * p * denom) % mod

print(ans[n])

# AC, expected value
