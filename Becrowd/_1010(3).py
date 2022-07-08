# #1010 Simple Calculate Adapted by Neilor Tonin
A,B,C = map(float, input().split())
total = B * C
A,B,C = map(float, input().split())
total = (B*C) + total

print ("VALO A PAGAR: R$ {:.2f}".format(total))

#Ok