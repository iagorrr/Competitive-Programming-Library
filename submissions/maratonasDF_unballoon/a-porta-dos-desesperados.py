c = input()
r, g, b = map(int, input().split())
if c == "R":
    ans = 1 / r
if c == "B":
    ans = 1 / b
if c == "G":
    ans = 1 / g

print(f"{ans:.9f}")
