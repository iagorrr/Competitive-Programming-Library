#3039 Santa's toys Matheus Fabian.

#First recieve the total of childrens.
total = int(input())

#Declaring the variables for cars and dolls.
dolls = 0
car = 0

#Recieving the name and the sex of each children, and according with the sex increasing the variable dolls or car
for x in range (0, total):
    info = input().split()

    sex = info[1]

    if (sex == "F"):
        dolls = dolls + 1
    else:
        car = car + 1


#Just showing the output
print (f'{car} carrinhos')
print (f'{dolls} bonecas')

#Done.