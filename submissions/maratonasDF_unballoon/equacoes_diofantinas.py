n = int(input())
n -= 1

ans = n*(n-1)*(n-2)
ans = ans // (3*2)
print(ans)
