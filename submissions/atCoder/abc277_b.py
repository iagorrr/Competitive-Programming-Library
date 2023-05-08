# iagorrr ;)
n = int(input())

ans = "Yes"
mapa = []
for a in range(0, n):
    s = input()

    if s in mapa:
        ans = "No"

    if(s[0] not in 'HDCS'):
        
        ans = "No"
    
    if s[1] not in "A23456789TJQK":
        
        ans = "No"
    mapa.append(s)

print(ans)

#Accepted.