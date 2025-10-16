// Another Brick in the Wall
// https://www.acmicpc.net/problem/32916

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int l, h;
	cin >> l >> h;
	if (l % 2 == 1) {
		cout << h << '\n';
	} else {
		cout << (h / 2 * 2) << '\n';
	}
}

// 길이 l 높이 h의 벽을 1*2 벽돌로 세울 때, 사이를 메꾸기 위해 필요한 1*3 블록의 최소 개수 구하기