// '나교수' 교수님의 악필
// https://www.acmicpc.net/problem/16462

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (char& c : s) {
			if (c == '0' || c == '6') {
				c = '9';
			}
		}
		sum += min(100, stoi(s));
	}
	sum /= n;
	cout << round(sum);
}

// 주어진 성적들에서 0/6/9를 모두 9로 치환한(max 100) 성적 평균을 정수로 출력하기

// 점수를 문자열로 받아서 숫자를 바꾼 후 평균 구하기 - round도 쓰고