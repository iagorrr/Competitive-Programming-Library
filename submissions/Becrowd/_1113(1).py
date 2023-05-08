# #1113 Ascending and Descending by Neilor Tonin

a, b = map(int, input().split())
while a != b:

    if  a > b:
        print("Decrescente")
    elif a < b:
        print("Crescente")
    a, b = map(int, input().split())
    
# Accepted