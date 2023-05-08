X, Y = input().split()

X = float(X)
Y = float(Y)


if (X == 0):
    if (Y == 0):
        print ("Origem")
    else:
        print("Eixo Y")
elif (X > 0):
    if (Y == 0):
        print("Eixo X")
    elif (Y < 0):
        print("Q4")
    elif (Y > 0):
        print ("Q1")
else:
    if (Y == 0):
        print("Eixo X")
    elif (Y < 0):
        print ("Q3")
    elif (Y > 0):
        print("Q2")