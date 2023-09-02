// FizzBuzz
// https://www.acmicpc.net/problem/28702

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	string a, b, c;
	cin >> a >> b >> c;
	int target = 0;
	if (isdigit(c[0])) {
		target = stoi(c) + 1;
	} else if (isdigit(b[0])) {
		target = stoi(b) + 2;
	} else if (isdigit(a[0])) {
		target = stoi(a) + 3;
	}

	if (target % 15 == 0) {
		cout << "FizzBuzz";
	} else if (target % 5 == 0) {
		cout << "Buzz";
	} else if (target % 3 == 0) {
		cout << "Fizz";
	} else {
		cout << target;
	}
	cout << '\n';
}

// 3의 배수일 때 Fizz, 5의 배수일 때 Buzz, 3의 배수이자 5의 배수일 때 FizzBuzz일 때, 연속된 수 3개의 출력 상태를 보고 다음 수 출력하기

// 369가 아니고 배수이므로 세 수 모두 문자열이 찍힐 수는 없음 - 따라서 세 수 중 하나는 무조건 정수고, 이를 이용해 세 수 다음 수를 알 수 있음
// 이걸 이용해 FizzBuzz 판정해서 출력하면 됩니다