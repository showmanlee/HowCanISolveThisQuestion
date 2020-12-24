// Day 23: BST Level-Order Traversal
// https://www.hackerrank.com/challenges/30-binary-trees/problem

using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Node{
    public Node left,right;
    public int data;
    public Node(int data){
        this.data=data;
        left=right=null;
    }
}
class Solution{

	static void levelOrder(Node root){
  		Queue<Node> q = new Queue<Node>();
        q.Enqueue(root);
        while (q.Count != 0){
            Node p = q.Dequeue();
            Console.Write(p.data + " ");
            if (p.left != null)
                q.Enqueue(p.left);
            if (p.right != null)
                q.Enqueue(p.right);      
        }
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
        levelOrder(root);
        
    }
}

// 레벨 오더로 이진 트리 순회하기
// BST 구현 - 큐