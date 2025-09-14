import math

def countPrime(n):
    cnt = 0

    for i in range(2, int(math.sqrt(n)) + 1):
        tmp = 0
        while(n % i == 0):
            tmp += 1
            n /= i

        cnt += tmp

        if (tmp > 1):
            return -1
        
    if (n != 1):
        cnt += 1

    return cnt & 1
        
N = int(input())
res = 1

for B in range(2, 100):
    cnt = countPrime(B)

    if cnt == -1:
        continue

    tmp = int(N ** (1.0 / B))
    while(tmp ** B <= N):
        tmp += 1
    while(tmp ** B > N):
        tmp -= 1

    if (cnt):
        res += tmp - 1
    else:
        res -= tmp - 1

print(res)