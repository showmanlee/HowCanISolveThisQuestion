# Day 12: Inheritance
# https://www.hackerrank.com/challenges/30-inheritance/problem

class Person:
	def __init__(self, firstName, lastName, idNumber):
		self.firstName = firstName
		self.lastName = lastName
		self.idNumber = idNumber
	def printPerson(self):
		print("Name:", self.lastName + ",", self.firstName)
		print("ID:", self.idNumber)

class Student(Person):
    def __init__(self, f, l, i, s):
        Person.__init__(self, f, l, i)
        self.scores = s
    def calculate(self):
        avg = sum(self.scores) / len(self.scores)
        if avg >= 90:
            return 'O'
        if avg >= 80:
            return 'E'
        if avg >= 70:
            return 'A'
        if avg >= 55:
            return 'P'
        if avg >= 40:
            return 'D'
        return 'T'

line = input().split()
firstName = line[0]
lastName = line[1]
idNum = line[2]
numScores = int(input()) # not needed for Python
scores = list( map(int, input().split()) )
s = Student(firstName, lastName, idNum, scores)
s.printPerson()
print("Grade:", s.calculate())

# 미리 만들어진 Person 클래스를 상속받아 scores 멤버 배열을 만들고, 해당 값의 평균으로 성적 출력하는 함수 만들기
# Python 클래스 조작 시 self 활용법 숙지할 것