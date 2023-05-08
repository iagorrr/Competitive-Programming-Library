# #1060 Postive Numbers by Neilor Tonin

# Reading the 6 numbers.
positive = 0
for i in range(0, 6):
    num = float(input())
    if  num > 0:
        positive += 1

print(f"{positive} valores positivos")