n = int(input())
a = list(map(int, input().split()))

if 2 * max(a) < sum(a):
    print("Yes")
else:
    print("No")