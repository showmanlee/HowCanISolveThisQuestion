// A → B
// https://www.acmicpc.net/problem/16953

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	queue<pair<int, long long>> q;
	long long n, m;
	cin >> n >> m;
	q.push(make_pair(1, n));
	while (!q.empty()) {
		if (q.front().second == m)
			break;
		pair<int, long long> p = q.front();
		q.pop();
		if (p.second * 2 <= m)
			q.push(make_pair(p.first + 1, p.second * 2));
		if (p.second * 10 + 1 <= m)
			q.push(make_pair(p.first + 1, p.second * 10 + 1));
	}
	if (q.empty())
		cout << -1 << '\n';
	else
		cout << q.front().first << '\n';
}

// 2를 곱하거나 뒤에 1을 붙여서 목표값를 만들 수 있는가? 있다면 얼마만에 만들 수 있는가?
// 둘 다 값을 증가시키는 것이기 때문에 값이 넘어서면 중단하기
// pair를 써서 연산 횟수와 값을 같이 저장해보자
// 10억을 100억으로 만들 수 있기 때문에 long long으로 저장