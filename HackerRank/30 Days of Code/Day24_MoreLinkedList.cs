// Day 24: More Linked Lists
// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem

using System;
using System.Collections.Generic;
class Node
{
	public int data;
	public Node next;
    public Node(int d){
        data=d;
        next=null;
    }
		
}
class Solution {

    public static Node removeDuplicates(Node head){
        if (head == null)
            return head;
        Node cur = head;
        while (cur.next != null){
            if (cur.data == cur.next.data)
                cur.next = cur.next.next;
            else
                cur = cur.next;
        }
        return head;
    }

	public static  Node insert(Node head,int data)
	{
        Node p=new Node(data);
		
		
		if(head==null)
			head=p;
		else if(head.next==null)
			head.next=p;
		else
		{
			Node start=head;
			while(start.next!=null)
				start=start.next;
			start.next=p;
			
		}
		return head;
    }
	public static void display(Node head)
	{
		Node start=head;
		while(start!=null)
		{
			Console.Write(start.data+" ");
			start=start.next;
		}
	}
    static void Main(String[] args) {
	
		Node head=null;
        int T=Int32.Parse(Console.ReadLine());
        while(T-->0){
            int data=Int32.Parse(Console.ReadLine());
            head=insert(head,data);
        }
      	head=removeDuplicates(head);
		display(head);
	}
}
	

// 오름차순으로 구성된 연결 리스트에서 중복되는 숫자 빼기
// 내 다음 숫자가 같으면 내 화살표를 내 다음 노드로 연결