# #1071 Sum of Cosecutive Odd Numbers I by neilor Tonin

start = int(input())
end = int(input())
summ = 0

if start < end:
    for i in range(start+1, end, 1):
        if i % 2 != 0:
            summ += i
elif start > end:
    for i in range(end+1, start, 1):
        if i % 2 != 0:
            summ += i

print(summ)
    