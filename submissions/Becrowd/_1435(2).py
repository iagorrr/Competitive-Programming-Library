# #1435 Square Matrix I adapted By Josué P. de Castro

# Function to create a matrix filed with zero, based on size.
def genereteMatrix(order):
    matrix = []
    for i in range(0, order):
        newLine = []
        for j in range(0, order):
            newLine.append(0)
        matrix.append(newLine[:])

    return matrix

while(True):

    # Receiving size of array.
    order = int(input())
    if order == 0:
        break
    
    # Generating and filling array.
    matrix = genereteMatrix(order)
    sHori = 0
    sVerti =0
    layer = 1
    maxTemp = order
    loops = int(order/2)
    if order % 2 != 0:
        loops += 1

    for l in range(0, loops):

        for i in range(sHori,maxTemp):
            for j in range(sVerti, maxTemp):
                matrix[i][j] = layer

        layer += 1
        sHori += 1
        sVerti += 1
        maxTemp -= 1

    # Showing output.
    for i in range(0, order):
        print(f"{ matrix[i][j]:3}",end='')
        for j in range(1, order):
            print(f"{matrix[i][j]:4}",end='')
        print("")
    print("")