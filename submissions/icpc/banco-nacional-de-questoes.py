a, b, c = map(int, input().split())
x = input()

if x == 'A':
    print(int(a + c*5/2 + b*3/2))
elif x == 'B':
    print(int(b + a*2/3 + c*5/3))
else:
    print(int(c + a*2/5 + b*3/5))
