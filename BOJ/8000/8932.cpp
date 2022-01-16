// 7종 경기
// https://www.acmicpc.net/problem/8932

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

float a[7] = { 9.23076, 1.84523, 56.0211, 4.99087, 0.188807, 15.9803, 0.11193 };
float b[7] = { 26.7, 75, 1.5, 42.5, 210, 3.8, 254 };
float c[7] = { 1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int res = 0;
		for (int i = 0; i < 7; i++) {
			int p;
			cin >> p;
			if (i == 0 || i == 3 || i == 6) {
				p = a[i] * pow(b[i] - p, c[i]);
			}
			else {
				p = a[i] * pow(p - b[i], c[i]);
			}
			res += p;
		}
		cout << res << '\n';
	}
}

// 경기마다 점수 산정 방식과 상수가 다른 7개의 종목 성적이 주어졌을 때, 최종 점수 구하기

// 문제에 나와있는 대로 계산해서 출력하기 - floor를 위해 결과값은 int로 저장
// 계수 C가 정수가 아니므로 b-p와 p-b를 반복문 하나로 계산할 수는 없음에 주의