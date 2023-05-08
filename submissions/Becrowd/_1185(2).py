# #1185 Above the Secundary Diagonal

operation = str(input())

array = []
totalSum = 0

for i in range(0, 12):
    array.append(list())
    for j in range(0, 12):
        array[i].append(float(input()))
        if j < 11-i:
            totalSum += array[i][j]
        

if operation == 'M':
    totalSum = totalSum/66
print(f"{totalSum:.1f}")

# Accepted