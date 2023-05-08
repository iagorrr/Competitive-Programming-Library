T = float(input())

print ("NOTAS:")
print (f"{int(T/100)} nota(s) de R$ 100.00")
T = T % 100

print (f"{int(T/50)} nota(s) de R$ 50.00")
T = T % 50

print (f"{int(T/20)} nota(s) de R$ 20.00")
T = T % 20

print (f"{int(T/10)} nota(s) de R$ 10.00")
T = T % 10

print (f"{int(T/5)} nota(s) de R$ 5.00")
T = T % 5

print (f"{int(T/2)} nota(s) de R$ 2.00")
T = T % 2

print("MOEDAS:")
print (f"{int(T/1)} moeda(s) de R$ 1.00")
T = T % 1

print (f"{int(T/0.5)} moeda(s) de R$ 0.50")
T = round((T % 0.5),2)

print (f"{int(T/0.25)} moeda(s) de R$ 0.25")
T = round((T % 0.25),2)

print (f"{int(T/0.10)} moeda(s) de R$ 0.10")
T = round((T % 0.10),2)

print (f"{int(T/0.05)} moeda(s) de R$ 0.05")
T = round((T % 0.05),2)

print (f"{int(T/0.01)} moeda(s) de R$ 0.01")
T = round((T % 0.01),2)

