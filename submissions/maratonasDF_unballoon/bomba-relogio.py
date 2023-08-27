x = int(input())

strans = ""
while str(x)[0] != "1":
    x *= 3
    x = int(str(x)[-18:])
    strans += "L"

strans += "R" * (len(str(x)) - 1)
print(len(strans))
print(strans)

# AC, math
