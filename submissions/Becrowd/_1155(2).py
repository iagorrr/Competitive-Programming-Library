# #1155 S Sequence adapted by Neilor Tonin
# S = 1 + 1/2 + 1/3 + … + 1/100
result = 0
for i in range(1, 101):
    result += 1/i
print(f"{result:.2f}")

# Accepted