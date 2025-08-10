x, y = map(int, input().split())
print("Bob") if abs(x - y) <= 1 else print("Alice")