// ブラックジャック (Blackjack)
// https://www.acmicpc.net/problem/33170

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, y, z;
	cin >> x >> y >> z;
	bool res = (x + y + z <= 21);
	cout << res << '\n';
}

// x+y+z가 21 이하인지 확인하기