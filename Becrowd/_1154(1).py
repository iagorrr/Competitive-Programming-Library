# #1154 Ages adapted by Neilor Tonin

temp = 0
ages = []
while (temp >= 0):
    ages.append(temp)
    temp = int(input())

average = round(sum(ages)/(len(ages)-1), 2) # -1 because we have added the 0 as the first element.
print(f"{average:.2f}")

# Accepted