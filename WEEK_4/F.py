s1 = input()
s2 = s1[1: ] + s1[: 1]
s3 = s2[1: ] + s2[: 1]

print(int(s1) + int(s2) + int(s3))