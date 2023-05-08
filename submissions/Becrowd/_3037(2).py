#3037 by Pedro S.L Rey

#First receive the total of test case.
N = int(input())

winnersList = []

#Receivin each test case.
for i in range (0, N):
    
    #Variables to acculmate the points of Joao e Maria.
    pointsJ = 0
    pointsM = 0

    #Receiving the Joao info.
    for j in range (0, 3):
        XD = input().split()

        d,x = XD
        D = int(d)
        X = int(x)
        pointsJ = pointsJ + (X * D)
    
    #Receiving the Maria info.
    for m in range (0, 3):
        XD = input().split()

        x, d = XD
        D = int(d)
        X = int(x)

        pointsM = pointsM + (X * D) 
    
    #Verifying which nome should be add to the winners list.
    if (pointsM > pointsJ):
        winnersList.append("MARIA")
    else:
        winnersList.append("JOAO")


#Just showing the winners list.
for w in winnersList:
    print(w)

#Done