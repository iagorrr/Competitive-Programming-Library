# #1118 Several Scores with Validation

average = 0
valid = 0
confirm = 0
while confirm != 2:
    num = float(input())

    if num > 10 or num < 0:
        print("nota invalida")
    else:
        average += num
        valid += 1

    if valid == 2:
        print(f"media = {average/valid:.2f}")
        while confirm != 1 and confirm != 2:
            confirm = int(input("novo calculo (1-sim 2-nao)\n"))
        if confirm == 1:
            average = 0
            valid = 0
            confirm = 0

# Accepted