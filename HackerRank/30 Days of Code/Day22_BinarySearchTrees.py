# Day 22: Binary Search Trees
# https://www.hackerrank.com/challenges/30-binary-search-trees/problem

class Node:
    def __init__(self,data):
        self.right=self.left=None
        self.data = data
class Solution:
    def insert(self,root,data):
        if root==None:
            return Node(data)
        else:
            if data<=root.data:
                cur=self.insert(root.left,data)
                root.left=cur
            else:
                cur=self.insert(root.right,data)
                root.right=cur
        return root

    def getHeight(self,root):
        left = 0
        right = 0
        if root.left != None:
            left = self.getHeight(root.left) + 1
        if root.right != None:
            right = self.getHeight(root.right) + 1
        if left < right:
            return right
        return left

T=int(input())
myTree=Solution()
root=None
for i in range(T):
    data=int(input())
    root=myTree.insert(root,data)
height=myTree.getHeight(root)
print(height)       

# 이진 탐색 트리의 최대 깊이 구하기
# 양쪽으로 재귀를 내려서 풀기