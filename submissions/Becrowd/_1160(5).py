# #1160 Population Increase adapted by Neilor Tonin

# total tests case
N = int(input())

for i in range(0, N):
    totA, totB, percA, percB = map(float, input().split())

    totYears = 0
    while(totYears <= 100) and (totA <= totB):
        # print(f"A: {totA} B: {totB}")

        totYears += 1
        totA = totA + int((totA/100) * percA)
        totB = totB + int((totB/100) * percB)

    
    if totYears > 100:
        print("Mais de 1 seculo.")
    else:
        print(f"{totYears} anos.")