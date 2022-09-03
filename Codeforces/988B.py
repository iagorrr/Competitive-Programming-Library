# iagorrr
n = int(input())

strings = []

for i in range(n):
    s = str(input())
    
    strings.append([len(s), s])

# sort the string by their lenght.
strings.sort()

# verify if the smallest is in their respective consecutive.
ans = "YES"
for i  in range(len(strings)-1):
    if(strings[i][1] not in strings[i+1][1]):
        ans = "NO"
        break

print(ans)
if(ans == "YES"):
    for s in strings:
        print(s[1])

# accepted.