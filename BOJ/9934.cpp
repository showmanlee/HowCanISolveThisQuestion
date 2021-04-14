// 완전 이진 트리
// https://www.acmicpc.net/problem/9934

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int k;
int board[2048];

void input(int idx, int level) {
	if (level == 1) {
		cin >> board[idx];
		return;
	}
	input(idx * 2, level - 1);
	cin >> board[idx];
	input(idx * 2 + 1, level - 1);

}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> k;
	input(1, k);
	int idx = 1;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < pow(2, i); j++) {
			cout << board[idx] << ' ';
			idx++;
		}
		cout << '\n';
	}
}

// 완전 이진 트리를 중위 순회한 결과가 있을 때, 이를 트리 형태로 출력하기
// 완전 이진 트리는 1차원 배열로 표현할 수 있음 - 왼쪽 자식은 i * 2, 오른쪽 자식은 i * 2 + 1
// 그러니 아예 트리 입력을 중위 순회 기반의 재귀함수에서 받아버리자 - level이 1, 그러니까 리프 노드에 왔으면 그냥 입력, 그렇지 않으면 중위 순회 형태로 호출 - 입력 호출
// 그리고나서는 레벨 순회 형식으로 출력하면 됨 - 한 레벨이 끝나면 줄바꿈