// What is n, Daddy?
// https://www.acmicpc.net/problem/6794

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int res = 0;
	for (int i = 0; i <= 5; i++) {
		for (int j = i; j <= 5; j++) {
			if (i + j == n) {
				res++;
			}
		}
	}
	cout << res << '\n';
}

// 주어진 수를 두 손으로 셀 수 있는 경우의 수 구하기

// 1~5까지는 한 손으로 셀 수 있고, 2~10까지는 두 손으로 셀 수 있으며, 6~10까지는 두 손으로밖에 못 셈
// 손 방향 중복은 제외하므로, 2개의 0~5 레인지 중 i <= j일 때 더해서 그 값이 나오면 경우의 수에 누적