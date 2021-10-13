// 2018년을 되돌아보며
// https://www.acmicpc.net/problem/16674

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> count(10);
	int res = 0;
	while (n != 0) {
		count[n % 10]++;
		n /= 10;
	}
	if (count[3] != 0 || count[4] != 0 || count[5] != 0 || count[6] != 0 || count[7] != 0 || count[9] != 0) {
		res = 0;
	}
	else {
		res = 1;
		if (count[2] != 0 && count[0] != 0 && count[1] != 0 && count[8] != 0) {
			res = 2;
		}
		if (count[2] == count[0] && count[0] == count[1] && count[1] == count[8]) {
			res = 8;
		}
	}
	cout << res << '\n';
}

// 주어진 수에 2, 0, 1, 8로만 이루어져 있는지(1), 그 중 2, 0, 1, 8이 모두 포함되어 있는지(2), 그 중 2, 0, 1, 8의 수가 모두 똑같은지(8) 판정하기

// 나오는 숫자들을 모두 세보고, 다른 수가 나온다면 0을 판정하고, 그렇지 않다면 위 조건에 입각하여 최종 판정하기