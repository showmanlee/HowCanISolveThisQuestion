// 더하기
// https://www.acmicpc.net/problem/10822

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int res = 0;
	string p;
	for (char c : s) {
		if (c == ',') {
			res += stoi(p);
			p = "";
		}
		else {
			p += c;
		}
	}
	res += stoi(p);
	cout << res << '\n';
}

// 숫자와 ,로 이루어진 문자열에서 ,로 구분된 수를 추출하여 모두 더하기

// 문자열이 정당하게 주어짐이 보장되기에 이를 고려하여 , 또는 문장 끝이 오기 전까지 숫자들을 누적한 뒤 , 및 문장 끝이 오면 정수로 바꾸어 결과값에 더하면 됨