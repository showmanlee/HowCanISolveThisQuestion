# Day 19. Interfaces
# https://www.hackerrank.com/challenges/30-interfaces/problem

class AdvancedArithmetic(object):
    def divisorSum(n):
        raise NotImplementedError

class Calculator(AdvancedArithmetic):
    def divisorSum(self, n):
        res = 0
        for i in range(1, n + 1):
            if n % i == 0:
                res += i
        return res


n = int(input())
my_calculator = Calculator()
s = my_calculator.divisorSum(n)
print("I implemented: " + type(my_calculator).__bases__[0].__name__)
print(s)

# 인터페이스 상속하여 실체화하기
# python에서는 별도의 인터페이스 클래스가 없고, 대신 인터페이스 클래스에서 오버라이딩하지 않으면 못 쓰도록 오류 걸어놓기