# 생일
# https://www.acmicpc.net/problem/5635

n = int(input())
students = []
for i in range(n):
    name, d, m, y = input().split()
    students.append([name, int(d), int(m), int(y)])
students.sort(key = lambda x : (-x[3], -x[2], -x[1]))
print(students[0][0])
print(students[-1][0])

# 유럽식 날짜 표기법에 주
