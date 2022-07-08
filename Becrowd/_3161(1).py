#The forgotten fruits by Elder Sobrinho UFTM.

#First receive thte fruits that Sheldon will eat, and how many elements have the list of the fruits that sheldon likes.
elements = input().split()

#Convert to a integer value and assing the first to the fruits that Sheldon will eat, and the second to the total of fruits in the list.
totalFruits = int(elements[0])

totalCodes = int(elements[1])

#Declare the lists to receive the fruits, and the "codes" in the list .
listFruits = [""]*totalFruits
listCodes = [""]*totalCodes

#Receiving the fruits.
for f in range(0, totalFruits):
    #Note that we gonna recieve each fruit as a lower case string.
    listFruits[f] = input().lower()

#Receiving the codes in the list.
for c in range(0, totalCodes):
    #The same here, receive the code, at the same time as convert to a lower case sting.
    listCodes[c] = input().lower()


#For each fruit verify the name of fruit itself and the reverse name of friut is in the code.
for f in (listFruits):
    eat = False
    fruitReversed = f[-1 :0:-1]

    #Verifying if the fruit and the reverse fruit is in the list of codes.
    for c in (listCodes):
        if ( (f in c) or (fruitReversed in c)):
            eat = True
            break
    if (eat == True):
        print ("Sheldon come a fruta %s" % f)
    else:
        print ("Sheldon detesta a fruta %s" % f)

#Done