
"""
    iagorrr ;)

    The best way to build is in a cube

    Instead of try to build the cube, imagine
    the smallest box you can put every package

    The area of the box is the total faces exposed.

    **** THE VOLUME MUST NE EXACTLY EQUAL TO N **** 
"""
n = int(input())
ans = 10**10
for a in range(1, 1+int(n**(1/2))):
    for b in range(1, 1+int(n**(1/2))):
        if n % (a*b) == 0:
            c = n//(a*b)
            faces = 2*(a*b + b*c + c*a)
            ans = min(ans, faces)
print(ans)
