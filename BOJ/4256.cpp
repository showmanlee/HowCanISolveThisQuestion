// 트리
// https://www.acmicpc.net/problem/4256

#include <iostream>
#include <vector>
using namespace std;

int preorder[1001];
int inorder[1001];
int postorder[1001];
int n;
int cur;

void travel(int idx, int left, int right) {
	if (left > right)
		return;
	if (left == right) {
		postorder[cur] = preorder[idx];
		cur++;
		return;
	}
	int pos = inorder[preorder[idx]];
	travel(idx + 1, left, pos - 1);
	travel(idx + pos - left + 1, pos + 1, right);
	postorder[cur] = preorder[idx];
	cur++;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		for (int i = 0; i < 1000; i++)
			preorder[i] = inorder[i] = postorder[i] = 0;

		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> preorder[i];
		for (int i = 1; i <= n; i++) {
			int p;
			cin >> p;
			inorder[p] = i;
		}
		cur = 1;
		travel(1, 1, n);
		for (int i = 1; i <= n; i++)
			cout << postorder[i] << ' ';
		cout << '\n';
	}
}

// 이진 트리를 전위 순회한 결과와 중위 순회한 결과가 주어졌을 때, 후위 순회 결과 출력하기

// 전위 순회(n-l-r)의 좋은 점 - (서브) 트리의 루트를 쉽게 알 수 있다
// 중위 순회(l-n-r)의 좋은 점 - 루트를 알고 있다면, 왼쪽 트리와 오른쪽 트리의 크기를 쉽게 알 수 있다
// 이 둘의 장점을 조합하여 트리를 순회하고, 이를 후위 순회하면 된다

// 전위 순회 배열에는 값을 저장하고, 중위 순회 배열에는 해당 값이 들어갈 인덱스를 저장한다
// 이렇게 해서 후위 순회 값을 얻는 데는 전위 순회 배열을 활용하고, 위치를 잡는데는 중위 순회 배열을 활용한다
// 순회를 위한 재귀함수에는 현재 표시할 값이 있는 위치, 그리고 현재 트리의 범위가 매개변수로 주어진다
// 트리 범위(left, right)를 통해 현재 탐색하는 서브트리의 크기를 알 수 있고, 위치값(idx)를 통해 현재 탐색하는 노드가 어떤 값을 가지고 있는지 알 수 있다
// 현재 탐색한 노드의 중위 순회 상 위치를 pos라고 할 때, 서브 트리의 범위는 left ~ pos - 1, pos + 1, right
// 그리고 서브 트리의 전위 순회 상 위치는 idx + 1, idx + pos - left + 1(idx + 왼쪽 트리 크기)