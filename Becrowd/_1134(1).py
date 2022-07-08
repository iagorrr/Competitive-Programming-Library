# #1134 Type of Fuel by Neilor Tonin

alcool = 0
gasolina = 0
diessel = 0
temp = 0
while(temp != 4):
    temp = int(input())

    if temp == 1:
        alcool += 1
    elif temp == 2:
        gasolina += 1
    elif temp == 3:
        diessel += 1
    elif temp == 4:
        break

print("MUITO OBRIGADO")
print(f"Alcool: {alcool}")
print(f"Gasolina: {gasolina}")
print(f"Diesel: {diessel}")

# Accepted
