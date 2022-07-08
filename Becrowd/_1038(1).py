A, B = input().split()
A = int(A)
B = int(B)

total = 0.0

if (A == 1):
    total = 4
elif (A == 2):
    total = 4.50
elif (A == 3):
    total = 5
elif (A == 4):
    total = 2
elif (A == 5):
    total = 1.50

total  = total * B

print ("Total: R$ %.2f" % total)