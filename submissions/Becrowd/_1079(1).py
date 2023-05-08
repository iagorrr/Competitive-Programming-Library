# #1079  Weighted average by Neilor Tonin

N = int(input())


for i in range(0, N):
    weigh = list(map(float, input().split()))
    weigh[0] *= 2
    weigh[1] *= 3
    weigh[2] *= 5
    print(f"{sum(weigh)/10:.1f}")

# Accepted