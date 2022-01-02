// 방학 숙제
// https://www.acmicpc.net/problem/5532

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int l;
	double a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	int res = l - ceil(max(a / c, b / d));
	cout << res << '\n';
}

// 국어 a페이지를 하루에 최대 c페이지 풀 수 있고, 수학 b페이지를 하루에 최대 d페이지 풀 수 있을 때, l일의 방학 중 놀 수 있는 최대 날짜 수는?

// 국어와 수학은 동시에 할 수 있음 - 따라서 a / c와 b / d 중 더 많은 쪽의 시간이 걸림
// 그러니 c/d문제 이하를 풀어도 하루를 소모해야 하기에 ceil을 적용하여 l에 빼주기