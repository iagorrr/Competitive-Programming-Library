# #1009 Salary with Bonus adapted by Neilor Tonin
name = str(input())
salary = float(input())
sold = float(input())

salary = salary + (sold/100) * 15

print("TOTAL = R$ {:.2f}".format(salary))