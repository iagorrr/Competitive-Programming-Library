# #1065 Even Between five numbers

# Receiving the five numbers and counting the even.
even = 0
for i in range(0, 5):
    num = int(input())
    if num % 2 == 0:
        even += 1

print(f"{even} valores pares")
