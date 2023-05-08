#1278 by Bruno Santos
import re

TotalLines = int(input())
while (TotalLines != 0):
    
    #First receiving each line and adding to an array.
    text = []
    biggerLine = -1
    for l in range(0, TotalLines):
        line = str(input())
        lineNoS = re.sub(r' +', '', line)

        if (len(lineNoS) > biggerLine):
            biggerLine = len(lineNoS)

        text.append(line)

    #Showing each line.
    for l in range(0, TotalLines):
        #Spaces.
        for s in range(0, biggerLine - len(text[l])):
    

    TotalLines = int(input())