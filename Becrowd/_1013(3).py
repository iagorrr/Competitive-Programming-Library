# #1013 The Greatest by Neilor Tonin

A, B, C = map(int, input().split())

if (A > B) and (A > C):
    A = A
elif (B > A) and (B > C):
    A = B
elif (C > B)and (C > B):
    A = C

print (f"{A} eh o maior")

#Ok