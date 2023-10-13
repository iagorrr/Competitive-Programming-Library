lst = list(map(int, input().split()))

if lst.count(1) + lst.count(0) != 8:
    print("F")
else:
    print("S")

# AC, ad-hoc
