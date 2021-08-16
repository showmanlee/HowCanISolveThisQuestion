// 비밀 편지
// https://www.acmicpc.net/problem/5426

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, string> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string s;
		cin >> s;
		int n = sqrt(s.length());
		for (int i = n - 1; i >= 0; i--)
			for (int j = 0; j < n; j++)
				cout << s[j * n + i];
		cout << '\n';
	}
}

// 어떤 문자열을 n*n 보드에 쓴 후 시계방향으로 90도 회전한 후 순서대로 다시 문자열로 옮긴 결과가 주어졌을 때, 원래 문자열 출력하기

// 변환된 보드에서 마지막 열부터 차례대로 위에서부터 내려가면 됨
// 별도의 2차원 배열로 바꾸지 말고, 입력되는 문자열의 길이로 한 변의 길이를 구한 후, 두 인덱스로 문자열 인덱스를 만들어 출력하기