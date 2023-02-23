# iagorrr :)

T = int(input())
for _ in range(T):
    n = int(input())
    ans = 0
    ans += n*(n+1)*(n*2+1)//6;
    ans += (n-1)*(n)*((n-1)*2+1)//6;
    ans += (n-1)*n//2;
    ans *= 2022
    print(ans%(int(1e9+7)))

# AC, math.
