# Day 24: More Linked Lists
# https://www.hackerrank.com/challenges/30-linked-list-deletion/problem

class Node:
    def __init__(self,data):
        self.data = data
        self.next = None 
class Solution: 
    def insert(self,head,data):
            p = Node(data)           
            if head==None:
                head=p
            elif head.next==None:
                head.next=p
            else:
                start=head
                while(start.next!=None):
                    start=start.next
                start.next=p
            return head  
    def display(self,head):
        current = head
        while current:
            print(current.data,end=' ')
            current = current.next

    def removeDuplicates(self,head):
        if head == None:
            return head
        cur = head
        while cur.next != None:
            if cur.data == cur.next.data:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return head

mylist= Solution()
T=int(input())
head=None
for i in range(T):
    data=int(input())
    head=mylist.insert(head,data)    
head=mylist.removeDuplicates(head)
mylist.display(head); 

# 오름차순으로 구성된 연결 리스트에서 중복되는 숫자 빼기
# 내 다음 숫자가 같으면 내 화살표를 내 다음 노드로 연결