# #1074  Even or Odd by Neilor Tonin

total = int(input())

for i in range(0, total):
    num = int(input())

    if num == 0:
        print("NULL")
    elif num % 2 == 0:
        print("EVEN ", end='')
    else:
        print("ODD ", end='')
    
    if num > 0:
        print("POSITIVE")
    elif num < 0:
        print("NEGATIVE")
    