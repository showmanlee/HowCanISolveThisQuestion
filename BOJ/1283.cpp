// 단축키 지정
// https://www.acmicpc.net/problem/1283

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string input;
	getline(cin, input);
	vector<bool> assigned(26);
	for (int t = 0; t < n; t++) {
		getline(cin, input);
		bool selected = false;
		for (int i = 0; i < input.length(); i++) {
			if (i == 0 || input[i - 1] == ' ') {
				char c = input[i];
				c = toupper(c);
				if (!assigned[c - 'A']) {
					assigned[c - 'A'] = true;
					selected = true;
					for (int j = 0; j < input.length(); j++) {
						if (i == j)
							cout << '[' << input[j] << ']';
						else
							cout << input[j];
					}
					cout << '\n';
					break;
				}
			}
		}
		if (selected)
			continue;
		for (int i = 0; i < input.length(); i++) {
			char c = input[i];
			if (c == ' ')
				continue;
			c = toupper(c);
			if (!assigned[c - 'A']) {
				assigned[c - 'A'] = true;
				selected = true;
				for (int j = 0; j < input.length(); j++) {
					if (i == j)
						cout << '[' << input[j] << ']';
					else
						cout << input[j];
				}
				cout << '\n';
				break;
			}
		}
		if (!selected)
			cout << input << '\n';
	}
}

// 주어진 명령의 이름을 바탕으로 단축키를 지정할 때, 지정되는 단축키의 위치는?
// 할당되지 않은 글자 중 각 단어의 첫 글자 -> 모든 글자 중 먼저 등장하는 글자 -> 할당하지 않음

// 시작하기 전 각 알파벳이 할당되었는지 표시하는 배열을 생성
// 일단 getline으로 명령을 통째로 받고, 처음에는 첫 글자와 공백 다음 글자를 탐색
// 만약 해당 글자가 할당되지 않은 글자일 경우, 해당 글자를 할당하고 할당된 결과를 출력
// 이렇게 했는데도 할당되지 않은 경우 모든 글자(공백 제외)에 대하여 다시 탐색 및 출력
// 최종적으로 할당되지 않은 경우 그냥 출력