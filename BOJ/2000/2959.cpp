// 거북이
// https://www.acmicpc.net/problem/2959

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> p(4);
	for (int i = 0; i < 4; i++) {
		cin >> p[i];
	}
	sort(p.begin(), p.end());
	cout << (p[0] * p[2]) << '\n';
}

// 주어진 4개의 선분으로 만들 수 있는 직사각형의 최대 넓이는?

// 선분을 정렬하고, 1/3번째 선분의 길이의 곱을 구하면 된다
// 마주보는 변이 만들어지려면 긴쪽의 길이는 버려져야 하고, 이 상황에서 최대한 긴 길이를 확보하려면 정렬한 순서대로 묶어주는 것이 이득