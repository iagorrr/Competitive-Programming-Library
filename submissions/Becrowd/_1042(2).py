# #1042 Simple Sort Adapted by Neilor Tonin
from abc import abstractproperty


A, B, C = map(int, input().split())

array = []
array.append(A)
array.append(B)
array.append(C)

arrayS = []
arrayS.append(A)
arrayS.append(B)
arrayS.append(C)

for a in range(0,3):
    for b in range(0,3):
        if (arrayS[a] < arrayS[b]):
            temp = arrayS[a]
            arrayS[a] = arrayS[b]
            arrayS[b] = temp

for a in arrayS:
    print (a)
print ("")

for a in array:
    print (a)
