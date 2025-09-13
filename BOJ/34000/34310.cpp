// No Stragglers
// https://www.acmicpc.net/problem/34310

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int stu = 0, fac = 0, vis = 0;
	for (int i = 0; i < n; i++) {
		string a, b;
		int c;
		cin >> a >> b >> c;
		int* target;
		if (a == "STU") {
			target = &stu;
		} else if (a == "FAC") {
			target = &fac;
		} else {
			target = &vis;
		}
		if (b == "IN") {
			*target += c;
		} else {
			*target -= c;
		}
	}
	int res = stu + fac + vis;
	if (res == 0) {
		cout << "NO STRAGGLERS\n";
	} else {
		cout << res << '\n';
	}
}

// 주어진 종류의 인원의 출입 현황이 주어질 때, 남은 인원이 있는지 구하기