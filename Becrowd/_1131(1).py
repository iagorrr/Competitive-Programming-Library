# #1131 Grenais adapted by Neilor Tonin

confirm = 0
win_inter = 0
win_gremio = 0
draws = 0
total_grenal = 0
while (confirm != 2):
    inter, gremio = map(int, input().split())

    # Winner
    if inter > gremio:
        win_inter += 1
    elif gremio > inter:
        win_gremio += 1
    else:
        draws += 1

    print("Novo grenal (1-sim 2-nao)")
    confirm = int(input())

    total_grenal += 1

print(f"{total_grenal} grenais")
print(f"Inter:{win_inter}")
print(f"Gremio:{win_gremio}")
print(f"Empates:{draws}")

if win_inter > win_gremio:
    print("Inter venceu mais")
elif win_gremio > win_inter:
    print("Gremio venceu mais")
else:
    print("Não houve vencedor")

# Accepted