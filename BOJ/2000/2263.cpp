// 트리의 순회
// https://www.acmicpc.net/problem/2263

#include <iostream>
#include <vector>
using namespace std;

int inorder[100001];
int postorder[100001];
int preorder[100001];
int n;
int cur;

void travel(int idx, int left, int right) {
	if (left > right)
		return;
	preorder[cur] = postorder[idx];
	cur++;
	if (left == right)
		return;
	int pos = inorder[postorder[idx]];
	travel(idx - 1 - right + pos, left, pos - 1);
	travel(idx - 1, pos + 1, right);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		inorder[p] = i;
	}
	for (int i = 1; i <= n; i++)
		cin >> postorder[i];
	cur = 1;
	travel(n, 1, n);
	for (int i = 1; i <= n; i++)
		cout << preorder[i] << ' ';
	cout << '\n';
}

// 이진 트리를 중위 순회한 결과와 후위 순회한 결과가 주어졌을 때, 전위 순회 결과 출력하기

// 후위 순회 배열에서 루트가 무엇인지 알 수 있고, 이렇게 얻은 루트의 위치를 중위 순회 배열에서 찾으면 왼쪽 트리와 오른쪽 트리의 크기가 얼마나 되는지 확인할 수 있다
// 이를 위해 중위 순회 배열로 인덱스를 받도록 조정 - 해당 수가 중위 순회의 어디서 등장하는지 나타내기
// 트리 순회 특성 상 재귀 함수를 이용하여 순회를 진행할 수 있음 - 매개 변수는 후위 순회 상에서 내 위치(idx), 트리의 범위(left, right)를 주고, 루트(postorder[n])부터 순회 시작
// 전위 순회이므로 먼저 현재 노드를 출력한 후, 왼쪽/오른쪽 순서대로 재귀하며 탐색한다 - 그 과정에서 현재 노드의 중위순회 등장 위치를 pos로 둔다
// 왼쪽 서브트리의 루트는 idx - 1 - right + pos(루트에서 오른쪽 트리 뒤의 노드), 범위는 left ~ pos - 1
// 오른쪽 서브 트리의 루트는 idx - 1(루트 바로 왼쪽 노드), pos + 1 ~ right