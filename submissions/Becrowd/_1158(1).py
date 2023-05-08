# #1158 Sum of consecutive odd Numbers III adapted by Neilor Tonin

# Function to sum total of odd numbers.
def sumOdd(X, Y):
    odds = 0
    numTemp = X
    totSum = 0

    while(odds < Y):
        if numTemp % 2 != 0:
            totSum += numTemp
            odds += 1

        numTemp += 1
    
    return totSum

# Total test cases.
N = int(input())

# Each one
for i in range(0, N):
    X, Y = map(int, input().split())
    print(sumOdd(X,Y))

