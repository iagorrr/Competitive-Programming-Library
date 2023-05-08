# #1012 Area Adapted by Neilor Tonin
A, B, C = map(float, input().split())

print ("TRIANGULO: {:.3f}".format((A*C)/2))
print ("CIRCULO: {:.3f}".format(C*C * 3.14159))
print ("TRAPEZIO: {:.3f}".format(((A+B)*C)/2))
print ("QUADRADO: {:.3f}".format(B*B))
print ("RETANGULO: {:.3f}".format(A*B))

#Ok
