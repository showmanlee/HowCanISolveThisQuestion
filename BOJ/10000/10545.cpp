// 뚜기뚜기메뚜기
// https://www.acmicpc.net/problem/10545

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	vector<string> letter = {
		"2", "22", "222",
		"3", "33", "333",
		"4", "44", "444",
		"5", "55", "555",
		"6", "66", "666",
		"7", "77", "777", "7777",
		"8", "88", "888",
		"9", "99", "999", "9999"
	};
	vector<int> button(10);
	for (int i = 1; i <= 9; i++) {
		int p;
		cin >> p;
		button[p] = i;
	}
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (i != 0 && letter[s[i - 1] - 'a'][0] == letter[s[i] - 'a'][0]) {
			cout << '#';
		}
		for (char c : letter[s[i] - 'a']) {
			cout << button[c - '0'];
		}
	}
	cout << '\n';
}

// 입력이 꼬인 숫자 패드에서 누르는 버튼과 대응되는 실제 입력이 주어지고, 쳐야 하는 영타가 주어졌을 때, 해당 영타를 치기 위해 눌러야 하는 버튼 입력 구하기

// 버튼 입력은 1~9까지, 해당 위치에 대응하는 입력이 주어짐 - 첫 번째 자리에 2가 들어갔다면 '2' 입력을 주기 위해 1을 눌러야 한다는 말
// 해당 글자를 치기 위한 정상적인 입력을 각 알파벳에 대응하도록 배열에 정리해주고, 받는 입력에 대응해 누르는 버튼을 나타내는 배열도 준비해둔다
// 이를 이용해 각 문자를 받으며 해당되는 번호로 변환해서 출력 - 맞닿은 문자가 같은 키를 눌러야하는 경우 중간에 # 출력하기