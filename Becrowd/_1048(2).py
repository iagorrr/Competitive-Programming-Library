# #1048 Salry Increase by Neilor Tonin

# receiving the input.
salary = float(input())
ajuste = 0

# calculating increase according with the salary.
if (salary <= 400):
    newsalary = salary*1.15
    perc = 15
elif (salary  <= 800):
    newsalary = salary*1.12
    perc = 12
elif (salary <= 1200):
    newsalary = salary*1.10
    perc = 10
elif (salary <= 2000):
    newsalary = salary*1.07
    perc = 7
else:
    newsalary = salary*1.04
    perc = 4

# output.
print(f"Novo salario: {newsalary:.2f}")
print(f"Reajuste ganho: {newsalary-salary:.2f}")
print(f"Em percentual: {perc} %")

