# #1044 adpted by Neilor Tonin
A = input()
A = A.split()

if (int(A[1]) % int(A[0]) == 0) or ((int(A[0]) % int(A[1]) == 0)):
    print ("Sao Multiplos")
else:
    print ("Nao sao Multiplos")