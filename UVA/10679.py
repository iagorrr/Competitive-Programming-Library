n = int(input())
for i in range(n):
    s = str(input())
    m = int(input())
    aux = {}
    for j in range(m):
        t = str(input())
        if aux.get(t, -1) == -1:
            if s.find(t) == -1:
                aux[t] = 0
                print('n')
            else:
                aux[t] = 1
                print('y')
        else:
            print('y' if aux[t]==1 else 'n')