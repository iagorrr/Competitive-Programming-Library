# #1072 Interval 2 by Neilor Tonin

total = int(input())
totalIn = 0

for i in range(0, total):
    num = int(input())

    if num >= 10 and num <= 20:
        totalIn += 1

print(f"{totalIn} in")
print(f"{total - totalIn} out")