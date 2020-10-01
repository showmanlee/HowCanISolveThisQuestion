# 이상한 곱셈
# https://www.acmicpc.net/problem/1225

a, b = input().split()
an = bn = 0
for i in a:
    an += int(i)
for j in b:
    bn += int(j)
print(an * bn)

# 10000자리 숫자라서 O(n^2)로 풀면 타임아웃 가능성이 있음
# 곱셈공식을 적용해보면 (a의 자릿수의 합)(b의 자릿수의 합)으로도 구할 수 있어요
# 이러면 O(n)으로 풀이 가능
