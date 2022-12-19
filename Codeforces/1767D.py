n = int(input())
s = str(input())
x  = s.count('1')
y = s.count('0')

for i in range(2**x, 2**(x+y) - 2**y +1 + 1):
    print(i, end=' ')

print()
// AC

