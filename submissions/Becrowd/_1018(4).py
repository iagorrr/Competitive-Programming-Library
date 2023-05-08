T = int(input())
print(T)
print (f"{int(T/100)} nota(s) de R$ 100,00")
T = T % 100

print (f"{int(T/50)} nota(s) de R$ 50,00")
T = T % 50

print (f"{int(T/20)} nota(s) de R$ 20,00")
T = T % 20

print (f"{int(T/10)} nota(s) de R$ 10,00")
T = T % 10

print (f"{int(T/5)} nota(s) de R$ 5,00")
T = T % 5

print (f"{int(T/2)} nota(s) de R$ 2,00")
T = T % 2

print (f"{int(T/1)} nota(s) de R$ 1,00")
T = T % 1