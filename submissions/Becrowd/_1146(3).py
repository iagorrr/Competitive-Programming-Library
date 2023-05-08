# #1146 Growing Sequences adapted by Neilor Tonin

sample = 3
while(sample != 0):
    sample = int(input())
    if sample == 0:
        break

    print("1", end='')
    for i in range(2, sample+1):
        print(f" {i}",end='')
    print('')

# Accepted