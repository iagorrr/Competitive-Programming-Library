# #1046 Game time Adapted by Neilor Tonin

# receiving inputs.
start, end = map(int, input().split())

# calculating.
total = 0
if start < end:
    total = end - start
else:
    total = 24 - start + end

# output.
print(f"O JOGO DUROU {total} HORA(S)")
