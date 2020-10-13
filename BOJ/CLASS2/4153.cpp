// 직각삼각형
// https://www.acmicpc.net/problem/4153

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	while (true) {
		vector<int> l(3);
		cin >> l[0] >> l[1] >> l[2];
		if (l[0] == 0 && l[1] == 0 && l[2] == 0)
			break;
		sort(l.begin(), l.end());
		if (l[0] * l[0] + l[1] * l[1] == l[2] * l[2])
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
}

// 피타고라스가 보고 있다
// a, b, c가 오름차순으로 주어진다는 보장이 없음 - 정렬