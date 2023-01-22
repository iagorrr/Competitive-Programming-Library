# iagorrr ;)

t = int(input())

for _ in range(t):
    x, y = map(int, input().split())

    layer = max(x, y)

    an = 1 + (layer-1-1) * 2 # total of elements in the previous laye. 

    sn = (layer-1) * int((1 + an)/2) # sum of elements until the previous layer. 

    l = sn + 1 # lowest value of the current layer
    r = l + an + 2 - 1 # hightst value of the current layerself.
    
    # if is increasing or decreasing layer.
    if layer % 2 == 0:
        p = r
        sign = -1
    else:
        p = l
        sign = 1
    if y < x:  # is in the line.
        ans = p + sign*(y-1) 
    else: # is in the row, sum the total to cross the line and go 'uper' in the row.
        ans = p + sign*(layer+(layer-x)-1)

    print(ans)

# AC.
