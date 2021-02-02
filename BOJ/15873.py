# 공백 없는 A+B
# https://www.acmicpc.net/problem/15873

s = input()
if s[1] == '0':
    print(int(s[0:2]) + int(s[2:]))
else:
    print(int(s[0]) + int(s[1:]))

# 1~10까지의 자연수 2개가 공백 없이 주어질 때 합 구하기
# 0이 나오는 경우는 10이 나올 때 뿐 - 중간에 0이 나오면 A가 10이고, 그렇지 않으면 B가 10일 수 있음