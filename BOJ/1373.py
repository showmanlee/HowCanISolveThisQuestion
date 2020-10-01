# 2진수 8진수
# https://www.acmicpc.net/problem/1373

two = input()
eight = ""
length = len(two)
first = length % 3
if first == 1:
    eight += two[0]
elif first == 2:
    eight += str(int(two[0]) * 2 + int(two[1]))

while first < length:
    part = two[first:first + 3]
    eight += str(int(part[0]) * 4 + int(part[1]) * 2 + int(part[2]))
    first += 3

print(eight)

# 2진수 3자리가 8진수
