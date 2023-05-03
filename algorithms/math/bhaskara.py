"""
iagorrr ;)

bhaskara

delta = b^2 + 4ac

x = -b +- sqrt(detla)
        2a
"""
from math import sqrt

a, b, c = map(int, input().split())

delta = b**2 - 4*a*c
if a == 0 and b == 0 and c == 0:# infinite root. 
    print(-1)
elif a == 0 and b == 0:# no root.
    print(0)
elif a == 0: # one root.
    print(1)
    print(-c / b)
elif delta < 0: # no root.
    print(0)
elif delta == 0: # one root.
    print(1)
    x1 = (-b ) / (2*a)
    print(x1)
else: # two distinct root.
    x1 = (-b + sqrt(delta)) / (2*a)
    x2 = (-b - sqrt(delta))/ (2*a)
    print(2)
    if(x1 > x2):
        t = x1;
        x1 = x2
        x2 = t
    print(x1)
    print(x2)

