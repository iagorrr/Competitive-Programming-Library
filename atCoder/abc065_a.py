# iagorrr ;)
x, a, b = map(int,(input().split()))
if a + x < b:
    print("dangerous")
elif a + x == b:
    print("safe")
elif a >= b:
    print("delicious")
else:
    print("safe")
# AC.
