# #1049 Animal by Neilor Tonin

# receiving inputs.
first = str(input())
second = str(input())
third = str(input())

# finding animal according.
if first == "vertebrado":
    if second == "ave":
        if third == "carnivoro":
            animal = "aguia"
        else:
            animal = "pomba"
    else:
        if third == "onivoro":
            animal = "homem"
        else:
            animal = "vaca"
else:
    if second == "inseto":
        if third == "hematofago":
            animal = "pulga"
        else:
            animal = "lagarta"
    else:
        if third == "hematofago":
            animal = "sanguessuga"
        else:
            animal = "minhoca"

# output.
print(animal)
