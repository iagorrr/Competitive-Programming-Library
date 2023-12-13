m, a =  map(float, input().split())
k = m *a - a
ans = -k / (1+m)
print("{:.20f}".format(ans))

