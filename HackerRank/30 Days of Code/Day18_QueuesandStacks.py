# Day 18: Queues and Stacks
# https://www.hackerrank.com/challenges/30-queues-stacks/problem

import sys

class Solution:
    def __init__(self):
        self.st = []
        self.qu = []
    def pushCharacter(self, c):
        self.st.append(c)
    def enqueueCharacter(self, c):
        self.qu.append(c)
    def popCharacter(self):
        return self.st.pop()
    def dequeueCharacter(self):
        return self.qu.pop(0);

# read the string s
s=input()
#Create the Solution class object
obj=Solution()   

l=len(s)
# push/enqueue all the characters of string s to stack
for i in range(l):
    obj.pushCharacter(s[i])
    obj.enqueueCharacter(s[i])
    
isPalindrome=True
'''
pop the top character from stack
dequeue the first character from queue
compare both the characters
''' 
for i in range(l // 2):
    if obj.popCharacter()!=obj.dequeueCharacter():
        isPalindrome=False
        break
#finally print whether string s is palindrome or not.
if isPalindrome:
    print("The word, "+s+", is a palindrome.")
else:
    print("The word, "+s+", is not a palindrome.")    

# 스택과 큐를 이용해 펠린드롬 확인하기(스택과 큐에 문자들을 집어넣고 뺀 결과가 모두 같으면 펠린드롬)
# st = [], st.append(1), st.pop()
# qu = [], qu.append(1), qu.pop(0)