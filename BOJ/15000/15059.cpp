// Hard choice
// https://www.acmicpc.net/problem/15059

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int res = (d - a < 0 ? 0 : d - a) + (e - b < 0 ? 0 : e - b) + (f - c < 0 ? 0 : f - c);
	cout << res << '\n';
}

// 준비된 닭고기, 소고기, 파스타 기내식의 수와 승객들의 선호 메뉴 현황이 주어졌을 때, 원하는 메뉴를 받지 못하게 되는 승객의 수는?

// 준비된 기내식 수보다 원하는 사람의 수가 더 많으면 카운트, 그렇지 않으면 패스