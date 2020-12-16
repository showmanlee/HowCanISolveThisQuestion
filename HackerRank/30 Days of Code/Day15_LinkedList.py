# Day 15: Linked List
# https://www.hackerrank.com/challenges/30-linked-list/problem

class Node:
    def __init__(self,data):
        self.data = data
        self.next = None 
class Solution: 
    def display(self,head):
        current = head
        while current:
            print(current.data,end=' ')
            current = current.next

    def insert(self,head,data): 
        if head == None:
            head = Node(data)
        else:
            cur = head
            while cur.next:
                cur = cur.next
            cur.next = Node(data)  
        return head     

mylist= Solution()
T=int(input())
head=None
for i in range(T):
    data=int(input())
    head=mylist.insert(head,data)    
mylist.display(head); 	  

# 연결 리스트 구현
# Python에서 null은 None으로 표현, 대부분 참조형