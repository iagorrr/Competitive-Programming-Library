def asum(s, d, n):
	return (s + (s + d * (n-1))) * n // 2

n, b = map(int, input().split())

def until(c):
	initial = 4 * (n-c*2+2) - 4
	delta = 8
	terms = c
	return asum(initial, delta, terms)

def check(c):
	return until(c) < b

l = 0
r = n//2
max_layers = 0
while l <= r:
	mid = (l+r) // 2
	if check(mid):
		max_layers = max(max_layers, mid)
		l = mid + 1
	else:
	 	r = mid - 1

x = max_layers + 1
y = max_layers + 1
b = b - until(max_layers) -1
sz = n - max_layers*2

dec = min(sz-1, b)	
y = y + dec
b -= dec

dec = min(sz-1, b)
x = x + dec
b -= dec

dec = min(sz-1, b)
y = y - dec
b -= dec

dec = min(sz-1, b)
x = x - dec
b -= dec

print(x, y)

# AC, ad-hoc, math
