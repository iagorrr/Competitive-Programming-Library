#Even Squere, Adappted by Neilor Tonin 1073

#Receive the N number, in this case a integer.
N = int(input())

#Now with a loop from 2 to N, print the square of each number of the even, note that is from 2 to N not the numbers between.
for x in range (2, (N+1), 1):
    if ((x % 2) == 0):
        square = x*x
        print ("{}^2 = {}".format(x, square))

#Done.