# #1176 Fibonacci Array
def fibo(x):
    if x == 0:
        return 0
    elif x == 1:
        return 1
    
    now = 1
    previous = 1
    for i in range(0, x-2):
        now = previous + now
        previous = now - previous 
    return now

N = int(input())
for i in range(0, N):
    x = int(input())
    print(f"Fib({x}) = {fibo(x)}")

