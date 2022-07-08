
A, B, C, D = map(int, input())

verify = True

if ((B <= C) or (D <= A) or ((C+D) <= (A+B))):
    verify = False

if ((C < 0) or (D < 0) or (A < 0) or (B < 0)):
    verify = False

if (A % 2 != 0):
    verify = False

if (verify == False):
    print ("Valores nao aceitos")
else:
    print ("Valores aceitos")
