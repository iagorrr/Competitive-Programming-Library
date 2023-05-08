# iagorrr ;)
def main():
    N = int(input())

    vectorS = list()
    for _ in range(N):
        s = str(input())
        vectorS.append(s)

    ans = 0
    for i, x in enumerate(vectorS):
        for j,y in enumerate(vectorS):
            #print(f"{i} {x} {j} {y}")
            if x in y and i != j:
                ans += 1

    print(ans)

if __name__ == "__main__":
    main()

# 40/100 TLE