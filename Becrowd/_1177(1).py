# #1177 Array Fill II adapted by Neilor Tonin
N = int(input())

M = 0
for i in range(0, 1000):
    print(f"N[{i}] = {M}")
    M += 1
    if M == N:
        M = 0

# Accepted