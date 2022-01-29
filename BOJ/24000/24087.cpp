// アイスクリーム (Ice Cream) 
// https://www.acmicpc.net/problem/24087

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double s, a, b;
	cin >> s >> a >> b;
	s -= a;
	if (s <= 0) {
		cout << 250 << '\n';
	}
	else {
		cout << (250 + ceil(s / b) * 100) << '\n';
	}
}

// 기본 a cm는 250원, 추가 b cm는 100원인 아이스크림이 있을 때, s cm 이상의 아이스크림을 사기 위해 필요한 비용은?

// 실제로 그만큼 쌓아서 비용을 구하면 되지요 - 위와 같이08:18 22-01-28