# #1156 S Sequence II Adapted by Neilor Tonin
# S = 1 + 3/2 + 5/4 + 7/8 + ... + 39/?

S = 0
j = 1
for i in range(1, 40, 2):
    # print(f"{i}/{j}")
    S += i/j
    j *= 2
print(f"{S:.2f}")

# Accepted