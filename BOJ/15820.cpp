// 맞았는데 왜 틀리죠?
// https://www.acmicpc.net/problem/15820

#include <iostream>
using namespace std;

int main(void) {
	int status = 0;
	int s, t;
	cin >> s >> t;
	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;
		if (a != b && status == 0) {
			status = 1;
		}
	}
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		if (a != b) {
			if (status == 0)
				status = 2;
		}
	}
	if (status == 0)
		cout << "Accepted" << '\n';
	else if (status == 1)
		cout << "Wrong Answer" << '\n';
	else
		cout << "Why Wrong!!!" << '\n';
}

// 샘플 테케와 시스템 테케로 구분, 샘플 테케가 틀린 경우와 시스템 테케만 틀린 경우, 그리고 모두 맞은 경우를 판단하라
// BOJ 고인물들이 가장 듣기 싫어하는 말 압도적 1위