# #1098 Sequence IJ 4 by Neilor Tonin

i = 0
j = 1
print("I=0 J=1\nI=0 J=2\nI=0 J=3")
i = round(i+0.2, 2)
j = round(j+0.2, 2)
while(i <= 2):
    for k in range(0, 3):
        if int(i) == float(i):
            print(f"I={int(i)} ", end='')
        else:
            print(f"I={i:.1f} ", end='')
        
        if int(j) == float(j):
            print(f"J={int(j+k)}")
        else:
            print(f"J={(k+j):.1f}")
        # print(f"I={i:.1f} J={(j+k):.1f}")
    i = round(i+0.2, 2)
    j = round(j+0.2, 2)

# Accepted
