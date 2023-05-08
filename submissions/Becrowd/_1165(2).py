# #1165 Prime Number adapted by Neilor Tonin

# Function to check if a number is prime.
def isPrime(N):
    for i in range(2, int(N/2) + 1):
        if N % i == 0:
            return False
    
    return True

# total test cases
N = int(input())

for i in range(0, N):
    num = int(input())
    if isPrime(num):
        print(f"{num} eh primo")
    else:
        print(f"{num} nao eh primo")