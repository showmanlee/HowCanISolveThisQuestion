// Day 24: More Linked Lists
// https://www.hackerrank.com/challenges/30-linked-list-deletion/problem

#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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

        Node* removeDuplicates(Node *head)
        {
            if (!head)
                return head;
    
            Node *cur = head;
            while (cur->next) {
                if (cur->data == cur->next->data) 
                    cur->next = cur->next->next;
                else
                    cur = cur->next;
            }
            return head;
        }

          Node* insert(Node *head,int data)
          {
               Node* p=new Node(data);
               if(head==NULL){
                   head=p;  

               }
               else if(head->next==NULL){
                   head->next=p;

               }
               else{
                   Node *start=head;
                   while(start->next!=NULL){
                       start=start->next;
                   }
                   start->next=p;   

               }
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
    head=mylist.removeDuplicates(head);

	mylist.display(head);
		
}

// 오름차순으로 구성된 연결 리스트에서 중복되는 숫자 빼기
// 내 다음 숫자가 같으면 내 화살표를 내 다음 노드로 연결