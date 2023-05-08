# #1188 Inferior Area by Neilor Tonin

operation = str(input())

totalSum = 0
for i in range(0, 12):
    for j in range(0,12):
        element = float(input())
        if i > j and 12 - j <= i:
            totalSum += element


if operation == 'M':
    totalSum = totalSum/30

print(f"{totalSum:.1f}")


