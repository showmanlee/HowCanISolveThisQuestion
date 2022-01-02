# 6174
# https://www.acmicpc.net/problem/9047

def convert(s):
    ret = ""
    for c in s:
        ret += c
    return ret

n = int(input())
for i in range(n):
    num = input()
    count = 0
    if num == "6174":
        print(count)
        continue
    while True:
        count += 1
        small = sorted(list(num))
        big = sorted(list(num), reverse=True)
        res = int(convert(big)) - int(convert(small))
        if res == 6174:
            print(count)
            break
        num = str(res)
        if len(num) < 4:
            for j in range(4 - len(num)):
                num = "0" + num

# 계산한 숫자가 4글자 미만인 경우 핸들링 필요
