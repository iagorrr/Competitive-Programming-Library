# #1047 Game Time with minutes adapted by Neilor Tonin
# from random import randint
# Receiving inputs.
hStart, mStart, hEnd, mEnd = map(int, input().split())
# hStart = randint(0,23)
# mStart = randint(0,59)
# hEnd = randint(0,23)
# mEnd = randint(0,59)
# print(f"{hStart} {mStart} {hEnd} {mEnd}")
# Caculating.
# Hour.
if hStart == hEnd:
    if mStart < mEnd:
        hTotal = 0
    elif mStart == mEnd:
        hTotal = 24
    elif mStart > mEnd:
        hTotal = 24
elif hStart < hEnd:
    hTotal = hEnd - hStart
elif hStart > hEnd:
    hTotal = 24 - hStart + hEnd


# Mins.
if mStart < mEnd:
    mTotal = mEnd - mStart
elif mStart == mEnd:
    mTotal = 0
elif mStart > mEnd:
    hTotal -= 1
    mTotal = 60 - mStart + mEnd


            

# Output.
print(f"O JOGO DUROU {hTotal} HORA(S) E {mTotal} MINUTO(S)")
