#2060 Bino's Challenge by Thalyson Nepomuceno

#First receive the total of inputs.
N = int(input())

#Them receive each number in one single line, as a vetor of strings.
numbers = input().split()

#Initializating the variables to receive the total of multiples.
multiples2 = 0
multiples3 = 0
multiples4 = 0
multiples5 = 0

#For each number received verify for each number it's a multiple
for n in numbers:
    nInt = int(n)
    if (nInt % 2 == 0):
        multiples2 = multiples2+1
    if (nInt % 3 == 0):
        multiples3 = multiples3+1
    if (nInt % 4 == 0):
        multiples4 = multiples4+1
    if (nInt % 5 == 0):
        multiples5 = multiples5+1

#Just showing how much multiples each number has.
print (f'{multiples2} Multiplo(s) de 2')
print (f'{multiples3} Multiplo(s) de 3')
print (f'{multiples4} Multiplo(s) de 4')
print (f'{multiples5} Multiplo(s) de 5')

#Done