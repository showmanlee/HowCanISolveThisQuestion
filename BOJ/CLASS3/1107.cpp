// 리모컨
// https://www.acmicpc.net/problem/1107

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	int dest, n;
	cin >> dest >> n;
	vector<bool> broken(10);
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		broken[p] = true;
	}
	int res = abs(dest - 100);
	for (int i = 0; i <= 1000000; i++) {
		bool pass = false;
		string p = to_string(i);
		for (char c : p) {
			if (broken[c - '0']) {
				pass = true;
				break;
			}
		}
		if (pass)
			continue;
		res = min(res, abs(dest - i) + (int)p.length());
	}
	cout << res << '\n';
}

// 버튼 몇 개가 고장한 리모컨으로 100번에서 원하는 채널 번호로 이동할 때, 버튼(숫자, +-)을 최소로 누르고 움직일 수 있는 경우는?
// 채널이 무한개가 있긴 하나 목표는 500000 안에서 주어지고, 따라서 0~1000000 범위에서 계산하면 브루트포스로 충분히 가능
// 초기값은 +-만 눌렀을 때 나오는 횟수로 하고, 이후 0~1000000 순회하면서 안 고장난 숫자만 쓰였으면 횟수 계산(절댓값 + 버튼 수) 후 갱신
