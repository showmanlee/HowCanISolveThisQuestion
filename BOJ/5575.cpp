// 타임 카드
// https://www.acmicpc.net/problem/5575

#include <iostream>
using namespace std;

class Time {
public:
	int hour;
	int minute;
	int second;
	Time& operator-=(Time& t) {
		this->second -= t.second;
		if (this->second < 0) {
			this->second += 60;
			this->minute--;
		}
		this->minute -= t.minute;
		if (this->minute < 0) {
			this->minute += 60;
			this->hour--;
		}
		this->hour -= t.hour;
		return *this;
	}
};

int main(void) {
	Time t[3][2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++)
			cin >> t[i][j].hour >> t[i][j].minute >> t[i][j].second;
		t[i][1] -= t[i][0];
	}
	for (int i = 0; i < 3; i++) {
		cout << t[i][1].hour << ' ' << t[i][1].minute << ' ' << t[i][1].second << '\n';
	}
}

// C++식 시간 계산
// 이번에도 클래스를 만들어서 써보자