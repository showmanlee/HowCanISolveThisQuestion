// 극장 좌석
// https://www.acmicpc.net/problem/2302

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> fib(41);
	fib[0] = fib[1] = 1;
	for (int i = 2; i <= 40; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	int n, m;
	cin >> n >> m;
	vector<int> vip(m + 1);
	for (int i = 0; i < m; i++) {
		cin >> vip[i];
	}
	vip[m] = n + 1;
	int res = 1;
	int beg = 0;
	for (int i : vip) {
		int end = i;
		res *= fib[end - beg - 1];
		beg = end;
	}

	cout << res << '\n';
}

// 일렬로 주어진 좌석표에서 VIP를 제외한 나머지 사람들은 원래 자리에서 양옆의 자리에 앉을 수 있을 때, 앉을 수 있는 경우의 수 구하기

// VIP석은 움직일 수 없으므로 VIP석 사이사이에서 나올 수 있는 경우의 수를 생각해보면 됨
// 1 = 1
// 2 = 12 21
// 3 = 123 213 132
// 4 = 1234 2134 1324 1243 2143
// ... 이런 식으로 서로 바꾸지 않은 맞붙은 자리 2개를 뒤집는 경우를 구할 수 있음 - 그리고 그렇게 얻은 경우의 수는 피보나치임
// 따라서 일반 영역의 길이마다 피보나치를 곱한 게 답