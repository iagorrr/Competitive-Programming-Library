# #1159 Sum of consecutive even numbers adapted by Neilor Tonin

# Function to sum the five first even numbers.
def sumEven5(X):
    totSum = 0
    evens = 0
    numTemp = X

    while(evens < 5):
        if numTemp % 2 == 0:
            totSum += numTemp
            evens += 1

        numTemp += 1
    
    return totSum

test = 1
while(test != 0):
    test = int(input())
    if test == 0:
        break
    else:
        print(sumEven5(test))
    