#3209 by Mats Petter Petterson 

#Firs receive the total of tests case.
N = int(input())
result_list = []

#Now receive each test case, as a list of character
for i in range (0, N, 1):
    x = input().split()
    
    #Then for each character after the first one, convert to a interger them accumulate in one variable, after .
    #acculuate all values remove the total of power strips.
    sum = 1
    for a in range (1, int(x[0])+1):
        aint = int(x[a])
        sum = sum + aint
    sum = sum - int(x[0])
    result_list.append(sum)

#Now just show each element of the list.
for a in result_list:
    print(a)
    
#Done