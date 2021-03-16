// 그릇
// https://www.acmicpc.net/problem/7567

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	int res = 10;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != s[i - 1])
			res += 10;
		else
			res += 5;
	}
	cout << res << '\n';
}

// 그릇이 포개진 모양이 주어질 때, 쌓인 그릇의 높이 구하기
// 처음엔 무조건 10cm, 이후 정방향으로 쌓이면 +5, 역방향이면 +10