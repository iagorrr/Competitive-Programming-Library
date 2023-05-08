# #1186 Below the Secundary Diagonal by Neilor Tonin

operation = str(input())

totalSum = 0
for i in range(0, 12):
    for j in range(0,12):
        element = float(input())
        if 12-i <= j:
            totalSum += element


if operation == 'M':
    totalSum = totalSum/66

print(f"{totalSum:.1f}")


