def dis(x1, y1, x2, y2):
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)

Ax, Ay = map(int, input().split())
Bx, By = map(int, input().split())
Cx, Cy = map(int, input().split())

edges = [dis(Ax, Ay, Bx, By), dis(Bx, By, Cx, Cy), dis(Cx, Cy, Ax, Ay)]
if sum(edges) == 2 * max(edges) :
    print("Yes")
else:
    print("No")