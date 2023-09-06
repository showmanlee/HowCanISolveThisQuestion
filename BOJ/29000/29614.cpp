// 학점계산프로그램
// https://www.acmicpc.net/problem/29614

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	float sum = 0, cur = 0;
	int cnt = 0;
	for (char c : s) {
		if (c == '+') {
			cur += 0.5;
		} else {
			sum += cur;
			cur = 4 - (c - 'A');
			if (c == 'F') {
				cur = 0;
			}
			cnt++;
		}
	}
	sum += cur;
	float res = sum / cnt;
	cout << res << '\n';
}

// 받은 학점 목록이 문자열로 주어질 때, 평점 평균 구하기

// 적당히 잘 입력을 받아서 출력합니다