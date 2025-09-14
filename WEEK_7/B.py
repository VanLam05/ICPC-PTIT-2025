n = int(input())
lst = list(map(int, input().split()))
print((max(lst) + min(lst)) * (n + 1) // 2 - sum(lst))