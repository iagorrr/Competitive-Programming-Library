# #1132 Multiples of 13

# Reading values
start = int(input())
end = int(input())

# Swap if isn't in ascending order.
if start > end:
    temp = start
    start = end
    end = temp

# Sum all not divisible by 13.
total = 0
for i in range(start, end+1):
    if i % 13 != 0:
        total += i

# Show the sum
print(total)

# Accepted