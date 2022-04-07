// 자동완성
// https://www.acmicpc.net/problem/24883

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char c;
	cin >> c;
	if (c == 'N' || c == 'n') {
		cout << "Naver D2\n";
	}
	else {
		cout << "Naver Whale\n";
	}
}

// 알파벳 하나를 입력한 후 그게 N이라면 "Naver D2", 아니면 "Naver Whale" 출력하기

// 말 그대로...