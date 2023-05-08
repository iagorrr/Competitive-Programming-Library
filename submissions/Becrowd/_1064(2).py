# #1064 Positives and average by Neilor Tonin.

positive = []
for i in range(0,6):
    num = float(input())

    if num > 0:
        positive.append(num)

print(f"{len(positive)} valores positivos")
print(f"{(sum(positive)/len(positive)):.1f}")
