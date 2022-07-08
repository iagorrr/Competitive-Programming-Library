# #1117 Score Validation by Neior Tonin

average = 0
valid = 0
while valid < 2:
    num = float(input())

    if num > 10 or num < 0:
        print("nota invalida")
    else:
        average += num
        valid += 1

print(f"media = {average/valid:.2f}")

# Accepted