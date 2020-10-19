// 트리 순회
// https://www.acmicpc.net/problem/1991

#include <iostream>
#include <vector>
#include <string>
using namespace std;
string prefix = "";
string infix = "";
string postfix = "";

struct Node {
	char me = '-';
	int left = -1;
	int right = -1;
};

void preorder(vector<Node> nodes, int i) {
	prefix += nodes[i].me;
	if (nodes[i].left != -1)
		preorder(nodes, nodes[i].left);
	if (nodes[i].right != -1)
		preorder(nodes, nodes[i].right);
}

void inorder(vector<Node> nodes, int i) {
	if (nodes[i].left != -1)
		inorder(nodes, nodes[i].left);
	infix += nodes[i].me;
	if (nodes[i].right != -1)
		inorder(nodes, nodes[i].right);
}

void postorder(vector<Node> nodes, int i) {
	if (nodes[i].left != -1)
		postorder(nodes, nodes[i].left);
	if (nodes[i].right != -1)
		postorder(nodes, nodes[i].right);
	postfix += nodes[i].me;
}

int main(void) {
	int n;
	cin >> n;
	vector<Node> nodes(n);
	for (int i = 0; i < n; i++) {
		char m, l, r;
		cin >> m >> l >> r;
		nodes[m - 'A'].me = m;
		if (l != '.')
			nodes[m - 'A'].left = l - 'A';
		if (r != '.')
			nodes[m - 'A'].right = r - 'A';
	}
	preorder(nodes, 0);
	inorder(nodes, 0);
	postorder(nodes, 0);
	cout << prefix << '\n' << infix << '\n' << postfix << '\n';
}

// 노드는 언제나 알파벳 순으로 제공됨
// 이런 식의 트리 순회는 언제나 노드 당 한 번만 순회