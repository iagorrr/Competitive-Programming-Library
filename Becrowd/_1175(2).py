# #1175 Aray Change I adapted by Neilor Tonin

array = []
for i in range(0, 20):
    array.append(int(input()))

array.reverse()

for i, a in enumerate(array):
    print(f"N[{i}] = {a}")
