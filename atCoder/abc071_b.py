# iagorrr ;)
import string
s = input()

a = list(string.ascii_lowercase)
ans = None
for c in a:
    if c not in s:
        ans = c
        break

print(ans)
# AC.
