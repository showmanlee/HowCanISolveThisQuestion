# Day 4: Class vs. Instance
# https://www.hackerrank.com/challenges/30-class-vs-instance/problem

class Person:
    def __init__(self,initialAge):
        self.age = initialAge
        if self.age < 0:
            print("Age is not valid, setting age to 0.")
            self.age = 0
    def amIOld(self):
        if self.age < 13:
            print("You are young.")
        elif self.age >= 13 and self.age < 18:
            print("You are a teenager.")
        else:
            print("You are old.")
    def yearPasses(self):
        self.age += 1

t = int(input())
for i in range(0, t):
    age = int(input())         
    p = Person(age)  
    p.amIOld()
    for j in range(0, 3):
        p.yearPasses()       
    p.amIOld()
    print("")

# 클래스 만들기
# Python에서 클래스 만들고, 함수 정의하고, 객체 만들기
# Python에서는 멤버 변수를 __init__에서 self.age 처럼 선언
# 다른 언어처럼 클래스 안에 별도로 변수를 만든다면 그건 클래스 변수가 되어 다른 클래스 객체들이 공유하게 됨
# 멤버 함수는 안에 self 넣기