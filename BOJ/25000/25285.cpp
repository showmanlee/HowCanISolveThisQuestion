// 심준의 병역판정검사
// https://www.acmicpc.net/problem/25285

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		float a, b;
		cin >> a >> b;
		float bmi = b / ((a / 100) * (a / 100));
		int res = 0;
		if (a < 140.1) {
			res = 6;
		} else if (a >= 140.1 && a < 146) {
			res = 5;
		} else if (a >= 146 && a < 159) {
			res = 4;
		} else if (a >= 159 && a < 161) {
			if (bmi >= 16.0 && bmi < 35.0) {
				res = 3;
			} else {
				res = 4;
			}
		} else {
			if (bmi >= 20.0 && bmi < 25.0) {
				res = 1;
			} else if (bmi >= 18.5 && bmi < 20.0) {
				res = 2;
			} else if (bmi >= 25.0 && bmi < 30.0) {
				res = 2;
			} else if (bmi >= 16.0 && bmi < 18.5) {
				res = 3;
			} else if (bmi >= 30.0 && bmi < 35.0) {
				res = 3;
			} else {
				res = 4;
			}
		}
		cout << res << '\n';
	}
}

// 키와 몸무게가 주어질 때, 판정표에 따라 신검 등급 출력하기

// 표 보면서 분기 나눠서 출력해주기 - BMI 계산도 필요함
// 숫자는 최대 200까지만 주어지므로 200 이상은 고려할 필요 없ㅇㅁ