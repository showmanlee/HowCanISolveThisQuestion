// 더하기 3
// https://www.acmicpc.net/problem/11023

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, res = 0;
	while (cin >> n) {
		res += n;
	}
	cout << res << '\n';
}

// 주어진 수를 모두 더한 결과 출력하기

// while cin으로 들어오는 모든 수를 받고 더해서 출력하기...