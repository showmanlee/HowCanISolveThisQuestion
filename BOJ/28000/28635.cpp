// Индикатор
// https://www.acmicpc.net/problem/28635

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, a, b;
	cin >> m >> a >> b;
	int res = b - a;
	if (a > b) {
		res = b + m - a;
	}
	cout << res << '\n';
}

// 1부터 m까지 돌아가는 카운터에서 a에서 b로 가기 위해 필요한 버튼 조작 횟수 구하기