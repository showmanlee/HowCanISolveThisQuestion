// 빠른 무작위 메시지 전달
// https://www.acmicpc.net/problem/25825

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[12][12];
bool visited[12];
int res = 987654321;

void process(int p, int len, int cnt) {
	int pp = p / 2 * 2 + (p % 2 ? 0 : 1);
	visited[p] = true;
	visited[pp] = true;
	len += board[p][pp];
	if (cnt == 12) {
		res = min(res, len);
	} else {
		for (int i = 0; i < 12; i++) {
			if (!visited[i]) {
				process(i, len + board[pp][i], cnt + 2);
			}
		}
	}
	visited[p] = false;
	visited[pp] = false;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			cin >> board[i][j];
		}
		visited[i] = false;
	}
	for (int i = 0; i < 12; i++) {
		process(i, 0, 2);
	}
	cout << res << '\n';
}

// 1~12번의 번호가 주어진 학생들이 마주보는 번호 끼리 그룹으로 묶여 있고, 학생 간 메시지 전송 시간이 주어진다
// 선생님이 학생 1명에서 메시지를 보내고, 그 학생이 같은 그룹의 다른 학생에게 메시지를 보낸 후, 다른 학생이 다른 그룹에 메시지를 보내는 것을 모든 학생이 받을 떄까지 반복한다
// 이 상황에서 총 메시지 전송 시간의 최솟값은?

// 어떤 학생을 선택하면 다음 순서는 무조건 그 학생과 같은 그룹 학생 - 하지만 그룹에서 다른 그룹으로 넘어갈 때 선택한 학생에 따라 시간이 달라질 수 있음
// 즉, 이 문제는 단순히 12!도 아니고 6!도 아님 - 하지만 어찌됐든 브루트포스로 탐색은 가능함
// dfs로 탐색 들어갈 때 나와 같은 그룹의 거리 넣어주고, visit도 둘 다 체크해준다
// 그리고 들어갈 때는 그룹 단위가 아닌 사람 단위로 들어가되, cnt는 2 단위로 올려준다