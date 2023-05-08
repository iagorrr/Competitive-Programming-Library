# #1172 Array Replacement I adapted by Neilor Tonin

array = []
for i in range(0,10):
    num = int(input())
    if num <= 0:
        num = 1
    array.append(num)

for i,x in enumerate(array):
    print(f"X[{i}] = {x}")