// Do You Know Your ABCs?
// https://www.acmicpc.net/problem/20650

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(7);
	for (int i = 0; i < 7; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int a = v[0];
	int b = v[1];
	int c = v[6] - a - b;
	cout << a << ' ' << b << ' ' << c << '\n';
}

// a, b, c, a + b, a + c, b + c, a + b + c가 섞여서 주어질 때, a, b, c 구하기

// 주어진 수를 정렬했을 때 가장 앞의 수가 a고(a <= b <= c), 그 다음 수가 b이며, 가장 뒤의 수가 a + b + c임이 보장된다
// 따라서 이 값들만을 이용해 답을 구할 수 있음 - a + b + c - a - b = c