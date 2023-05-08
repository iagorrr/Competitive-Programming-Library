# #1116 Dividing X by Y by Neilor Tonin

N = int(input())
for i in range(0, N):
    a, b = map(int, input().split())

    if b == 0:
        print("divisao impossivel")
    else:
        c = a/b
        print(c)

# Accepted