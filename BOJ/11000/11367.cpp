// Report Card Time
// https://www.acmicpc.net/problem/11367

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int p;
		cin >> s >> p;
		cout << s << ' ';
		if (p >= 97)
			cout << "A+";
		else if (p >= 90)
			cout << "A";
		else if (p >= 87)
			cout << "B+";
		else if (p >= 80)
			cout << "B";
		else if (p >= 77)
			cout << "C+";
		else if (p >= 70)
			cout << "C";
		else if (p >= 67)
			cout << "D+";
		else if (p >= 60)
			cout << "D";
		else
			cout << "F";
		cout << '\n';
	}
}

// 각 학생의 이름과 점수가 주어질 때, 이름과 학점 출력하기

// 이름은 문자열로 받아 그대로 출력하고, 점수는 정수로 받아 조건문으로 학점으로 변환하기