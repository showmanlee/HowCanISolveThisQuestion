# Day 14: Scope
# https://www.hackerrank.com/challenges/30-scope/problem

class Difference:
    def __init__(self, a):
        self.__elements = a
        self.maximumDifference = 0
    
    def computeDifference(self):
        self.__elements.sort()
        for i in range(0, len(self.__elements) - 1):
            for j in range(i + 1, len(self.__elements)):
                if self.maximumDifference < self.__elements[j] - self.__elements[i]:
                    self.maximumDifference = self.__elements[j] - self.__elements[i]  

# End of Difference class

_ = input()
a = [int(e) for e in input().split(' ')]

d = Difference(a)
d.computeDifference()

print(d.maximumDifference)

# 배열과 배열 내 수의 차의 최댓값을 계산하는 함수를 가진 클래스 사용하기