x = input()
m = int(input())

d = int(max(x))

if len(x) == 1:
	print(int(d <= m))
	exit(0)


l = d+1 
r = m + 10


def check(mzin): 
	rx = x[::-1]
	p = 1
	ret = 0
	for j in rx:
		i = int(j)

		ret = ret + (i * p)

		p = p*mzin

		if ret > m:
			return False

		
	if ret <= m:
		return True
	else:
		return False

ans = 0
while l <= r:
	mid = (l + r)//2
	if check(mid):
		ans = max(ans, mid)
		l = mid + 1
	else:
		r = mid - 1

print(max(0, ans -d))

# AC, math, brute force, binary search
