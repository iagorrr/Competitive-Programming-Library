# # 1066 Eve, Odd, POsitive and Negative

positive = 0
negative = 0
odd = 0
even = 0

# Reding and increasing each count.
for i in range(0, 5):
    num = int(input())

    if num > 0:
        positive += 1
    elif num < 0:
        negative += 1

    if num % 2 == 0:
        even += 1
    else:
        odd += 1

print(f"{even} valor(es) par(es)")
print(f"{odd} valor(es) impar(es)")
print(f"{positive} valor(es) positivo(s)")
print(f"{negative} valor(es) negativo(s)")


