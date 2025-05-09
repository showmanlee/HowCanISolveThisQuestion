// 주차 요금 정산하기
// https://www.acmicpc.net/problem/33753

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, t;
	cin >> a >> b >> c >> t;
	int res = a;
	t -= min(30, t);
	res += c * ceil((double)t / b);
	cout << res << '\n';
}

// 기본 30분 A원에 추가 B분당 C원인 주차장에서 T분 주차했을 때 주차요금 구하기