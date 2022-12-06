// 2009년
// https://www.acmicpc.net/problem/2948

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string output[7] = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};
	int d, m;
	cin >> d >> m;
	int res = 0;
	for (int i = 0; i < m; i++) {
		res += month[i];
	}
	res += d;
	cout << output[res % 7] << '\n';
}

// 2009년의 한 날짜가 주어졌을 때, 무슨 요일인지 출력하기

// 2009년은 목요일부터 시작하는 평년 - 이를 이용해 적절히 몇일 째인지 계산하고, 나머지 연산으로 요일을 출력한다