A, B = input().split()
A, B = min(A, B), max(A, B)

print(min(A, B) * int(max(A, B)))