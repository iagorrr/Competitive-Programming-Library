mod = int(1e9 + 7)
for _ in range(int(input())):
    a, b, c = map(int, input().split())
    ans = (a - a * pow(a + b, mod - 2, mod) * c) % mod
    print(ans)

# Ac, math, expected value, modular arithmetic
