# #1150 Exceeding Z adapted by Neilor Tonin
X = int(input())

Y = 0
while(Y <= X):
    Y = int(input())

total = 1
totalSum = X
while(totalSum <= Y):
    X += 1
    totalSum = totalSum + X
    total += 1

print(total)

# Accepted
