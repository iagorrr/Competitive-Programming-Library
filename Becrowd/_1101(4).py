# #1101 Sequence of Numbers and sum

while(True):
    b, a = map(int, input().split())

    # Condition to stop read values
    if a <= 0 or b <= 0:
        break
    
    # If the second input is the largest, swap the values.
    if (a > b):
        c = a
        a = b
        b = c

    # Show the numbers between and find the sum
    sum = 0
    for i in range(a, b+1):
        print(f"{i} ", end='')
        sum += i
    print(f"Sum={sum}")

# Accepted