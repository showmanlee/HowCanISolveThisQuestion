// Ultimate Binary Watch
// https://www.acmicpc.net/problem/24578

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> num(4);
	for (int i = 0; i < 4; i++) {
		char c;
		cin >> c;
		num[i] = c - '0';
	}
	for (int i = 3; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (j == 2) {
				cout << "  ";
			}
			int p = num[j] / (int)pow(2, i) % 2;
			cout << (p ? '*' : '.');
			if (j != 3) {
				cout << ' ';
			}
		}
		cout << '\n';
	}
}

// 디지털 시계의 숫자 4개를 불 4개의 이진 형태로 출력하기

// 평소 이진수 출력하듯이 출력하기 - 각 자릿수에 맞게 수를 나눈 후 %2
// 출력 형식을 지켜야 함에 주의 - 각 자리 사이 공백 하나, 시와 분 사이에 공백 3개, 마지막에 공백 없음
// 그나저나 실제 손목시계로 나온 물건도 있네