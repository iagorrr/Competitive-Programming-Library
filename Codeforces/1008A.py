s = str(input())


ans = "YES"
if(len(s)==1 and s not in "aeioun"):
     ans = "NO"
for i in range(len(s)-1):
    if(s[i] not in "aeioun" and s[i+1] not in "aeiou"):
        ans = "NO"
        break
if(s[len(s)-1] not in "aeioun"):
    ans = "NO"

print(ans)

# AC