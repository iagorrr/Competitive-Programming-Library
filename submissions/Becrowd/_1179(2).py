# #1179 Fill Array IV adapted by Neilor Tonin
def showArray(name,array):
    for i,a in enumerate(array):
        print(f"{name}[{i}] = {a}")

even = []
odd = []

for i in range(0, 15):
    num = int(input())

    if num % 2 == 0:
        even.append(num)
    else:
        odd.append(num)

    if len(even) == 5:
        showArray("par", even)
        even = []

    if len(odd) == 5:
        showArray("impar", odd)
        odd = []

showArray("impar", odd)
showArray("par", even)

# Accepted