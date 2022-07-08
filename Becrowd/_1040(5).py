# #1040 adapted by Neilor Tonin
N1, N2, N3, N4 = input().split()
N1 = float(N1) * 2
N2 = float(N2) * 3
N3 = float(N3) * 4
N4 = float(N4) * 1
media = (N1 + N2 + N3 + N4)/10
print ("Media: %.1f" % media)

if (media >= 7):
    print ("Aluno aprovado.")
elif (media < 5):
    print ("Aluno reprovado.")
else:
    print ("Aluno em exame.")
    N5 = float(input())
    print ("Nota do exame: %.1f" % N5)
    media = (media+N5)/2
    if (media >= 5):
        print ("Aluno aprovado.")
    else:
        print ("Aluno reprovado")
    print ("Media final: %.1f" % media)