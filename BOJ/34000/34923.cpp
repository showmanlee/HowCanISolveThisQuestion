// 꼬마 미타
// https://www.acmicpc.net/problem/34923

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string x, y;
	cin >> x >> y;
	int a = (stoi(x.substr(0, 2)) - 1) * 60 + stoi(x.substr(3, 2));
	int b = (stoi(y.substr(0, 2)) - 1) * 60 + stoi(y.substr(3, 2));
	if (a < b) {
		swap(a, b);
	}
	int res = min(a - b, 720 + b - a) * 6;
	cout << res << '\n';
}

// 시계에서 다음 상태로 가기 위해 돌려야 하는 분침의 각도 구하기