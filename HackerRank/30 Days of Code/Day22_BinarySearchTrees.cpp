// Day 22: Binary Search Trees
// https://www.hackerrank.com/challenges/30-binary-search-trees/problem

#include <iostream>
#include <cstddef>

using namespace std;	

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

		int getHeight(Node* root){
            int ret = 0, left = 0, right = 0;
            if (root->left)
                left = getHeight(root->left) + 1;
            if (root->right)
                right = getHeight(root->right) + 1;
            if (left < right)
                ret = right;
            else 
                ret = left;
            return ret;
        }

}; //End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;

    return 0;
}

// 이진 탐색 트리의 최대 깊이 구하기
// 양쪽으로 재귀를 내려서 풀기