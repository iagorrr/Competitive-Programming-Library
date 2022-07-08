from typing import DefaultDict


days = int(input())

print (f"{int(days/365)} ano(s)")
days = days % 365

print (f"{int(days/30)} mes(es)")
days = days % 30

print (f"{days} dia(s)")