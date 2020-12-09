# Day 8: Dictionaries and Maps
# https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem

n = int(input())
m = {}
for i in range(n):
    s, p = input().split()
    m[s] = int(p)

while True:
    try:
        s = input()
    except:
        break
    if s in m:
        print(s + "=" + str(m[s]))
    else:
        print("Not found")

# n줄의 전화번호부와 *임의의 줄*의 검색이 주어졌을 때 결과 출력하기
# Dictionary 활용하기
# 그러면서 오류 핸들링도 활용하고