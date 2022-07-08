#Sum of consecutive odd numbers II Adapted by Neilor Tonin


#Receiving the total of tests case.
N = (int(input()))

sums = []

#Receiving each test case.
for i in range (0, N):
    #First receive the input as a list of strings.
    x = input().split() 

    #Each element of the list will be assigned to "a" and "b".
    a, b, = x 

    #Just converting to a integral number.
    num1 = int(a)
    num2 = int(b)

    #A variable to accumulate the sum.
    sum = 0
    
    
    #Will go from the biggest to the lowest number adding the odd numbers.
    #Remember to begin from the lowest + 1, because we need to sum the numbers BETWEEN.
    if (num1 > num2):
        #Loops to run through each element between the lowest and bigger number, and them sum if is a odd value.
        for i in range ((num2+1), num1):
            if (i % 2 != 0):
                sum = sum + i
    else:
        for i in range ((num1+1), num2):
            if (i % 2 != 0):
                sum = sum + i
    
    #Adding the sum to the list.
    sums.append(sum)

#Just showing each sum one by one.
for i in sums:
    print (i)

#Done.