// 오르막
// https://www.acmicpc.net/problem/14910

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	vector<int> v;
	while (cin >> n) {
		v.push_back(n);
	}
	int idx = -100000001;
	bool res = true;
	for (int i : v) {
		if (idx > i) {
			res = false;
			break;
		}
		idx = i;
	}
	cout << (res ? "Good" : "Bad") << '\n';
}

// 주어진 배열이 비내림차순인지 확인하기

// 그러니까 내 앞의 수가 나보다 작지 않은지 판정하라는 것
// 배열 크기가 주어지지 않으므로 while로 입력을 받고, 이후 배열을 돌며 내림차순인 상황이 있다면 실패 판정