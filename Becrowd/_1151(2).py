# #1151 Easy Fibonacci by Neilor Tonin

N = int(input())
previous = 0
now = 0
temp = 0
print(previous, end='')
now = 1
for i in range(0, N-1):
    print(f" {now}", end='')
    temp = now
    now += previous
    previous = temp
print('')

# Accepted