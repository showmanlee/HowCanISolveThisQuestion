// 꿍 가라사대
// https://www.acmicpc.net/problem/11094

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	getline(cin, s);
	int n = stoi(s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		if (s.substr(0, 10) == "Simon says") {
			cout << s.substr(10) << '\n';
		}
	}
}

// 주어진 문자열이 Simon says로 시작한다면, 그 뒷부분 출력하기

// getline으로 받아 substr로 판정하기
// Simon says 바로 뒤 공백부터 출력해야 함에 주의