# #1133 Rest of a Division

# Reading values
start = int(input())
end = int(input())
# Swap if they are not in ascending order.
if start > end:
    temp = start
    start = end
    end = temp

start += 1

# Print each number that match with the question.
for i in range(start, end):

    if (i % 5 == 2) or (i % 5 == 3):
        print(i)

# Accepted