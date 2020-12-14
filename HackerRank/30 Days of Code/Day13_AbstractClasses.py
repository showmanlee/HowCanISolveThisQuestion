# Day 13: Abstract Classes
# https://www.hackerrank.com/challenges/30-abstract-classes/problem

from abc import ABCMeta, abstractmethod
class Book(object, metaclass=ABCMeta):
    def __init__(self,title,author):
        self.title=title
        self.author=author   
    @abstractmethod
    def display(): pass

class MyBook(Book):
    def __init__(self, t, a, p):
        Book.__init__(self, t, a)
        self.price = p
    def display(self):
        print("Title: " + self.title)
        print("Author: " + self.author)
        print("Price: " + str(self.price))

title=input()
author=input()
price=int(input())
new_novel=MyBook(title,author,price)
new_novel.display()

# 추상 클래스를 상속받은 클래스 생성 및 사용
# Python에서 추상 클래스를 사용하려면 from abc import *를 해줘야 하고, 추상 클래스에 metaclass로 ABCMeta를 지정해줘야 함에 유의