#3174 by Jessica Dagostini

#Receiving the total of elves.
N = int(input())

#Declaring the variables to receive the total of hours that each group work.
hBonecos = 0
hArquitetos = 0
hMusicos = 0
hDesenhistas = 0

#Receiving the three information about each elf and adding the hours according with his respcive group.
for x in range(0, N):
    info = input().split()
    E, G, H = info
    intH = int(H)

    if (G == "bonecos"):
        hBonecos = hBonecos + intH
    elif (G == "arquitetos"):
        hArquitetos = hArquitetos + intH
    elif (G == "musicos"):
        hMusicos = hMusicos + intH
    else:
        hDesenhistas = hDesenhistas + intH

#One variable to receive the total of gifts produced per day, based in the time production of each group.
totalGifts = 0
totalGifts = int(hArquitetos/4) + totalGifts
totalGifts = int(hMusicos/6) + totalGifts
totalGifts = int(hDesenhistas/12) + totalGifts
totalGifts = int(hBonecos/8) + totalGifts

#Done just show the result.
print (totalGifts)

#Done