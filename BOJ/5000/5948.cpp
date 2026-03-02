// Bad Random Numbers
// https://www.acmicpc.net/problem/5948

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	vector<bool> visit(10001);
	while (!visit[n]) {
		res++;
		visit[n] = true;
		int p = (n / 10) % 100;
		n = p * p;
	}
	cout << res << '\n';
}

// 4자릿수의 가운데 2자리의 제곱을 연속해서 구할 때 같은 수로 수렴하는 연산 횟수 구하기