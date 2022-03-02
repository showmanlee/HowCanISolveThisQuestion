// 네 번째 수
// https://www.acmicpc.net/problem/2997

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];
	sort(v.begin(), v.end());
	if (v[1] - v[0] == v[2] - v[1]) {
		cout << v[2] + (v[2] - v[1]) << '\n';
	}
	else if (v[1] - v[0] > v[2] - v[1]) {
		cout << v[0] + (v[2] - v[1]) << '\n';
	}
	else {
		cout << v[1] + (v[1] - v[0]) << '\n';
	}
}

// 4항 등차수열에서 숫자 하나를 빼먹었을 때, 빼먹은 숫자 출력하기

// 우선 주어진 세 수를 정렬한다 - 붙은 두 수의 차는 등차의 1배 또는 2배
// 만약 둘 다 1배라면 처음이나 마지막 수에서 이어지는 등차수열을 출력
// 그렇지 않다면 2배인 쪽 왼쪽에서 1배를 더한 결과 출력