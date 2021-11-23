// 홍익 댄스파티
// https://www.acmicpc.net/problem/23321

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	string s;
	cin >> s;
	int n = s.length();
	vector<int> status(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') {
			status[i] = 1;
		}
	}
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') {
			status[i] = 0;
		}
		if (s[i] == '.') {
			status[i] = -1;
		}
	}
	cin >> s;
	cin >> s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (status[i] != -1) {
			status[i] = status[i] == 1 ? 0 : 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (status[i] == 1) {
			cout << 'o';
		}
		else {
			cout << '.';
		}
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		if (status[i] == 1) {
			cout << 'w';
		}
		else if (status[i] == 0) {
			cout << 'o';
		}
		else {
			cout << '.';
		}
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		if (status[i] == 1) {
			cout << 'l';
		}
		else if (status[i] == 0) {
			cout << 'm';
		}
		else {
			cout << 'o';
		}
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		if (status[i] == 1) {
			cout << 'n';
		}
		else if (status[i] == 0) {
			cout << 'l';
		}
		else {
			cout << 'L';
		}
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		if (status[i] == 1) {
			cout << '.';
		}
		else {
			cout << 'n';
		}
	}
	cout << '\n';
}

// 일렬로 서서 도약 중인 사람과 앉아있는 사람들의 모습이 주어질 때, 바로 다음 상태 출력하기

// 점프한 사람은 서있고, 서있는 사람은 점프하고, 앉아있는 사람은 그대로 있는다
// 각 사람은 세로로 주어지기에 다섯 줄을 모두 받고 출력해야하는데, 상태 판정 자체는 첫 두 줄로 할 수 있음
// 이렇게 첫 두 줄을 받아 사람 상태를 별도의 배열에 저장한 후, 나머지 줄을 입력받고, 상태를 바꾼 다음 조건에 맞게 출력한다