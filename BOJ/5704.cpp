// 팬그램
// https://www.acmicpc.net/problem/5704

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		string s;
		getline(cin, s);
		if (s == "*")
			break;
		vector<bool> visit(26);
		int remain = 26;
		for (char c : s) {
			if (c == ' ')
				continue;
			if (!visit[c - 'a'])
				remain--;
			visit[c - 'a'] = true;
		}
		cout << (remain == 0 ? "Y" : "N") << '\n';
	}
}

// 소문자로 구성된 문자열이 팬그램(모든 알파벳이 들어간 문장)인지 판별하기

// 문자열은 소문자와 공백만으로 구성됨이 보장됨 - 따라서 getline으로 문자열 받기
// 이후 각 알파벳이 등장했는지 표시하는 배열과 남은 알파벳의 수를 나타내는 변수를 생성, 모든 문자를 순회하며 체크되지 않은 알파벳이 등장한 경우 알파벳을 체크하고 남은 수를 하나 뺀다
// 이렇게 남은 수가 0이 되면 Y, 그렇지 않으면 N