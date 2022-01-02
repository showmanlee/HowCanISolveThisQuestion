// 풍선 터뜨리기
// https://www.acmicpc.net/problem/2346

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> board(n), res(n);
	for (int i = 0; i < n; i++)
		cin >> board[i];
	int idx = 0;
	for (int i = 0; i < n; i++) {
		res[i] = idx + 1;
		int dir = board[idx];
		board[idx] = 987654321;
		if (i == n - 1)
			break;
		while (dir != 0) {
			if (dir > 0) {
				idx = (idx + 1) % n;
				if (board[idx] != 987654321)
					dir--;
			}
			else if (dir < 0) {
				idx = (idx + n - 1) % n;
				if (board[idx] != 987654321)
					dir++;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << ' ';
	cout << '\n';
}

// 원형으로 놓인 숫자가 적힌 풍선을 1번부터 풍선에 적힌 숫자만큼 이동하면서 계속 터뜨린다고 할 때, 그 결과는?
// 원형으로 배치되어 있는 만큼 풍선 이동에는 나머지 연산을 사용해야 함 - 1~n 스케일을 0~n-1 스케일로 바꾸기

// 결과 배열에 현재 풍선 위치를 저장한 뒤, 풍선 배열에 해당 풍선이 터졌음을 표시
// 그 다음 풍선에 적힌 숫자 방향대로 이동하기 - 이동한 풍선이 터진 풍선이라면 숫자 소모하지 않고 다음 칸으로 이동하기
// 이 과정을 n번 반복 - 마지막에는 이동 과정을 다루지 않고 탈출하기