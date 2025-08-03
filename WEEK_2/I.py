import math
A, B, K = map(int, input().split())

while A or B:
    if math.comb(A + B - 1, B) >= K:
        print('a', end='')
        A -= 1
    else:
        K -= math.comb(A + B - 1, B)
        print('b', end='')
        B -= 1