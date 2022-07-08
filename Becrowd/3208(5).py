#3208 The embarrassed Cryptographer by Nils Grimsmo.

K = 1
L = 1

output = []
cont = 0

#Receive each test case until the input is iqual to 0 and 0.
info = input().split()
K = int(info[0])
L = int(info[1])

while ((K != 0) and (L != 0)) or (cont <= 20):

    #Finding which is the minimum number for the p
    
    prime = 2
    for p in range (2, L, 1):
        prime = p
        if (K % p == 0):
            output.append(p)
            break
       
    if ((prime+1) == L) :
          output.append(-1)

    #Receiving the input.
    info = input().split()
    K = int(info[0])
    L = int(info[1]) 

for o in output:
    if (o == -1):
        print ("GOOD")
    else:
        print (f'BAD {o}')