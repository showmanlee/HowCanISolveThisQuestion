// 탄산 음료
// https://www.acmicpc.net/problem/5032

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int e, f, c;
	cin >> e >> f >> c;
	int b = e + f;
	int res = 0;
	while (b >= c) {
		int bb = b / c;
		res += bb;
		b = b - (c * bb) + bb;
	}
	cout << res << '\n';
}

// 현재 가진 빈병의 개수, 새로 얻은 빈병 개수, 그리고 새로운 음료수를 얻기 위해 필요한 빈병 개수가 주어질 때, 음료수를 최대 몇 병까지 먹을 수 있는지 구하기

// 가진 빈병으로 얻은 음료수 역시 빈병으로 만들 수 있음 - 이를 고려하여 돌려봅시다