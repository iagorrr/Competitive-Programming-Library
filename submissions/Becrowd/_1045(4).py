# #1045 Triangle Types Adapted by Neilor Tonin

# Receiving sides.
sides = list(map(float, input().strip().split()))

# Arrange it in decreasing order.
sides.sort(reverse=True)

# Just to be easier to work
A = sides[0]
B = sides[1]
C = sides[2]

# Verifying each condition.
if A >= B + C:
    print("NAO FORMA TRIANGULO")
else:
    if A**2 == B**2 + C**2:
        print("TRIANGULO RETANGULO")
    elif A**2 > B**2 + C**2:
        print("TRIANGULO OBTUSANGULO")
    elif A**2 < B**2 + C**2:
        print("TRIANGULO ACUTANGULO")
        
    if A == B and A == C:
        print("TRIANGULO EQUILATERO")
    elif A == B or A == C or B == C:
        print("TRIANGULO ISOSCELES")

