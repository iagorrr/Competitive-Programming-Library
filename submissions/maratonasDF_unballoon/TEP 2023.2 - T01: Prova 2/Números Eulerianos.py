MAXN = 50
memo = list()
for i in range(MAXN+1):
	memo.append([])
	for j in range(MAXN+1):
		memo[i].append(-1)

def dp(n, k):
	if k == 0 or n-1 == k:
		return 1

	if memo[n][k] != -1:
		return memo[n][k]
	
	memo[n][k] = (n-k) * dp(n-1, k-1) + (k+1) * dp(n-1, k)

	return memo[n][k]

		
	
n, k = map(int, input().split())

print(dp(n, k))

# AC, dynamic programming
