# Day 17: More Exceptions
# https://www.hackerrank.com/challenges/30-more-exceptions/problem

class Calculator:
    def power(self, n, p):
        if n < 0 or p < 0:
            raise NameError("n and p should be non-negative")
        return n ** p

myCalculator=Calculator()
T=int(input())
for i in range(T):
    n,p = map(int, input().split())
    try:
        ans=myCalculator.power(n,p)
        print(ans)
    except Exception as e:
        print(e)   

# 예외 자체 생성 및 메시지 달기 - 주어진 코드에 예외 처리 코드가 있음에 주의
# raise NameError("...")