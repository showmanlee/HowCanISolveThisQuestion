// 결! 합!
// https://www.acmicpc.net/problem/16722

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<string>> board(10, vector<string>(3));
	vector<vector<vector<bool>>> hap(10, vector<vector<bool>>(10, vector<bool>(10)));
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];
	}
	int remain = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = i + 1; j <= 9; j++) {
			for (int k = j + 1; k <= 9; k++) {
				int h = 0;
				for (int l = 0; l < 3; l++) {
					if (board[i][l] == board[j][l] && board[i][l] == board[k][l] && board[j][l] == board[k][l])
						h++;
					if (board[i][l] != board[j][l] && board[i][l] != board[k][l] && board[j][l] != board[k][l])
						h++;
				}
				if (h == 3) {
					hap[i][j][k] = true;
					remain++;
				}
			}
		}
	}
	int n;
	cin >> n;
	int point = 0;
	bool guled = false;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == 'H') {
			vector<int> s(3);
			for (int j = 0; j < 3; j++)
				cin >> s[j];
			sort(s.begin(), s.end());
			if (hap[s[0]][s[1]][s[2]]) {
				hap[s[0]][s[1]][s[2]] = false;
				remain--;
				point++;
			}
			else
				point--;
		}
		else if (c == 'G') {
			if (remain == 0 && !guled) {
				point += 3;
				guled = true;
			}
			else
				point--;
		}
	}
	cout << point << '\n';
}

// 결! 합! 게임에서 게임판과 플레이어의 행동이 주어졌을 때, 플레이어가 얻은 점수는?

// 지니어스에도 나온 결! 합! 게임을 실제로 구현해보자
// - 배경(흰/회/검), 모양(동/세/네), 색(빨/노/파)가 각각 다른 27장의 카드 중 9장이 3*3 보드에 배치된다
// - 9장의 카드 중 3장을 골랐을 때, 각 카드의 속성이 모두 다르거나 모두 같으면 '합'이라고 한다
// - 플레이어는 매 턴마다 2가지 행동 중 하나를 할 수 있는데...
// - '합'과 함께 '합'을 이루는 카드 3개를 외친다 - 이때 카드가 '합'이라면 1점, '합'이 아니거나 이미 외쳤다면 -1점
// - '결'을 외친다 - 이때 만약 가능한 '합'이 없거나 '결'로 점수를 얻지 않았다면 3점, 아니라면 -1점

// 9장이 중복 없이 3개씩 조합되므로 사전에 충분히 '합' 여부를 확인할 수 있음
// 카드 조합(오름차순 정렬)이 '합'인지 확인하는 배열을 만들어 그 안에 '합' 여부를 표시하고, 표시된 '합' 개수를 따로 저장해 '결' 여부를 더 쉽게 판정할 수 있게 한다
// 만약 입력된 카드들이 '합'이라면 '합' 판정 후 '합' 확인 배열의 체크를 해제하고, 남은 '합' 개수를 줄인다
// '결'을 외친 상황에서 남은 '합'의 수가 0이고 이미 '결'을 외치지 않았다면 점수를 얻고 '결'을 외쳤다고 표시