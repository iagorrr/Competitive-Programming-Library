# #1050 DDD by Neilor Tonin

# receiving input.
ddd = str(input())

if ddd == "61":
    state = "Brasilia"
elif ddd == "71":
    state = "Salvador"
elif ddd == "11":
    state = "Sao Paulo"
elif ddd == "21":
    state = "Rio de Janeiro"
elif ddd == "32":
    state = "Juiz de Fora"
elif ddd == "19":
    state = "Campinas"
elif ddd == "27":
    state = "Vitoria"
elif ddd == "31":
    state = "Belo Horizonte"
else:
    state = "DDD nao cadastrado"

print(state)


