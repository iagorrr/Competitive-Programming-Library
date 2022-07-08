# #1080 Highest and position by Neilor Tonin

bigger = -1
position = 0
for i in range(0, 100):
    num = int(input())

    if bigger < num:
        bigger = num
        position = i+1

print(bigger)
print(position)

# Accepted.