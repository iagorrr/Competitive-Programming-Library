N = int(input())

for i in range(0, N):
    x, y = input().split()

    s = str(input())

    l = 0
    r = len(s)-1
    palindrome = True
    
    while(l < r):
        if(s[l] != s[r]):
            palindrome = False
            break
        l = l + 1
        r = r - 1

    if(int(y) == 0):
        print(1)
    elif(palindrome):
        print(1)
    else:
        print(2)
    