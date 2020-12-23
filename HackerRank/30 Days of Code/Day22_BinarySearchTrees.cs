// Day 22: Binary Search Trees
// https://www.hackerrank.com/challenges/30-binary-search-trees/problem

using System;
class Node{
    public Node left,right;
    public int data;
    public Node(int data){
        this.data=data;
        left=right=null;
    }
}
class Solution{

    static int getHeight(Node root){
        int left = 0, right = 0;
        if (root.left != null)
            left = getHeight(root.left) + 1;
        if (root.right != null)
            right = getHeight(root.right) + 1;
        if (left < right)
            return right;
        return left;
    }

	static Node insert(Node root, int data){
        if(root==null){
            return new Node(data);
        }
        else{
            Node cur;
            if(data<=root.data){
                cur=insert(root.left,data);
                root.left=cur;
            }
            else{
                cur=insert(root.right,data);
                root.right=cur;
            }
            return root;
        }
    }
    static void Main(String[] args){
        Node root=null;
        int T=Int32.Parse(Console.ReadLine());
        while(T-->0){
            int data=Int32.Parse(Console.ReadLine());
            root=insert(root,data);            
        }
        int height=getHeight(root);
        Console.WriteLine(height);
        
    }
}

// 이진 탐색 트리의 최대 깊이 구하기
// 양쪽으로 재귀를 내려서 풀기