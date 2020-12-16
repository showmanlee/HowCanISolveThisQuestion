// Day 15: Linked List
// https://www.hackerrank.com/challenges/30-linked-list/problem

#include <iostream>
#include <cstddef>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:

      Node* insert(Node *head,int data)
      {
          if (head){
            Node *cur = head;
            while(cur->next)
                cur = cur->next;
            cur->next = new Node(data);
          }
          else 
            head = new Node(data);
          return head;
      }

      void display(Node *head)
      {
          Node *start=head;
          while(start)
          {
              cout<<start->data<<" ";
              start=start->next;
          }
      }
};
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }	
	mylist.display(head);
		
}	  

// 연결 리스트 구현
// C++은 포인터로 구현