// 이진 검색 트리
// https://www.acmicpc.net/problem/5639

#include <iostream>
using namespace std;

struct node {
	int num;
	node* left;
	node* right;
};

void insert(int n, node* o) {
	if (n < o->num) {
		if (o->left)
			insert(n, o->left);
		else {
			o->left = new node;
			o->left->num = n;
			o->left->left = o->left->right = NULL;
		}
	}
	else {
		if (o->right)
			insert(n, o->right);
		else {
			o->right = new node;
			o->right->num = n;
			o->right->left = o->right->right = NULL;
		}
	}
}

void travel(node* o) {
	if (o == NULL)
		return;
	travel(o->left);
	travel(o->right);
	cout << o->num << '\n';
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	node* root = new node;
	root->num = n;
	root->left = root->right = NULL;
	while (cin >> n)
		insert(n, root);
	travel(root);
}

// 전위 순회 결과는 노드를 삽입한 순서로도 쓸 수 있다
// 아예 노드로 BST를 만들어서 풀어보자