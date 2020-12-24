# Day 23: BST Level-Order Traversal
# https://www.hackerrank.com/challenges/30-binary-trees/problem

import sys

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

    def levelOrder(self,root):
        q = [root]
        while len(q) != 0:
            print(q[0].data, end = " ")
            if q[0].left != None:
                q.append(q[0].left)
            if q[0].right != None:
                q.append(q[0].right)
            q.pop(0)            

T=int(input())
myTree=Solution()
root=None
for i in range(T):
    data=int(input())
    root=myTree.insert(root,data)
myTree.levelOrder(root)

# 레벨 오더로 이진 트리 순회하기
# BST 구현 - 큐