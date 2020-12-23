// Day 22: Binary Search Trees
// https://www.hackerrank.com/challenges/30-binary-search-trees/problem

import java.util.*;
import java.io.*;
class Node{
    Node left,right;
    int data;
    Node(int data){
        this.data=data;
        left=right=null;
    }
}
class Solution{

    public static int getHeight(Node root){
        int left = 0, right = 0;
        if (root.left != null)
            left = getHeight(root.left) + 1;
        if (root.right != null)
            right = getHeight(root.right) + 1;
        if (left < right)
            return right;
        return left;
    }

    public static Node insert(Node root,int data){
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
	 public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        Node root=null;
        while(T-->0){
            int data=sc.nextInt();
            root=insert(root,data);
        }
        int height=getHeight(root);
        System.out.println(height);
    }
}

// 이진 탐색 트리의 최대 깊이 구하기
// 양쪽으로 재귀를 내려서 풀기