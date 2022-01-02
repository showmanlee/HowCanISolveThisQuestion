// 학점계산
// https://www.acmicpc.net/problem/2754

#include <iostream>
#include <string>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	string res;
	if (s[0] == 'A') {
		if (s[1] == '+')
			res = "4.3";
		else if (s[1] == '0')
			res = "4.0";
		else if (s[1] == '-')
			res = "3.7";
	}
	else if (s[0] == 'B') {
		if (s[1] == '+')
			res = "3.3";
		else if (s[1] == '0')
			res = "3.0";
		else if (s[1] == '-')
			res = "2.7";
	}
	else if (s[0] == 'C') {
		if (s[1] == '+')
			res = "2.3";
		else if (s[1] == '0')
			res = "2.0";
		else if (s[1] == '-')
			res = "1.7";
	}
	else if (s[0] == 'D') {
		if (s[1] == '+')
			res = "1.3";
		else if (s[1] == '0')
			res = "1.0";
		else if (s[1] == '-')
			res = "0.7";
	}
	else
		res = "0.0";
	cout << res << '\n';
}

// A+ ~ F의 성적이 주어졌을 때, 4.3 스케일의 평점 출력하기
// 조건문의 반복 - double을 사용했다면 더 엘레강스하게 바꿀 수도 있을 것