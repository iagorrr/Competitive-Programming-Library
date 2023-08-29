a, b, c = map(int, input().split())
if a == b and c != a:
    print("C")
elif a != b and c == b:
    print("A")
elif a == c and b != c:
    print("B")
else:
    print("*")
