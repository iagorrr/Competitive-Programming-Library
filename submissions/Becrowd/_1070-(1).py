# #1070 Six Odd Numbers by Neilor Tonin

start = int(input())

if start % 2 == 0:
    start += 1

for i in range(0, 6):
    print(start)
    start += 2