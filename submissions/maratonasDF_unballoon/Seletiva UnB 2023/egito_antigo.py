from math import ceil, gcd

def solve(a, b):
	ans = list()

	while a: 
		"""
			a/b >= 1/d
			ad/b >= 1
			ad >= b
			d >= b/a
			d == roof(b/a)
		"""
		d = (a+b-1)//a 
		
		ans.append(d)
		
		# a/b - 1/d
		a = a * d - 1 * b
		b = b * d

		# simplifica
		g = gcd(a, b)		
		a //= g
		b //= g

	
	print("1/"+str(ans[0]), end='')
	for i in ans[1:]:
		print(" + 1/"+str(i), end='')
	print()


def main():
	n = int(input())
	for i in range(n):
		a, b = map(int, (input().split('/')))
		solve(a,b)
main()

# AC, math, bigint
