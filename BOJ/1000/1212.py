# 8진수 2진수
# https://www.acmicpc.net/problem/1212

eight = input()
two = ""
for c in eight:
    t = int(c)
    p = ""
    for i in range(3):
        p = str(t % 2) + p
        t //= 2
    two += p
if two[0:2] == "00":
    two = two[2:]
elif two[0] == "0":
    two = two[1:]
print(two)

# 8진수는 2진수 3자리를 묶어놓은 것
