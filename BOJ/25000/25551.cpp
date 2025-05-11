// 멋쟁이 포닉스
// https://www.acmicpc.net/problem/25551

#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int aa, ab, ba, bb, ca, cb;
	cin >> aa >> ab >> ba >> bb >> ca >> cb;
	int x = min(aa, min(bb, ca));
	int y = min(ab, min(ba, cb));
	int res = min(x, y + 1) + min(x + 1, y);
	cout << res << '\n';
}

// 2가지 색의 마스크, 티셔츠, 바지에서 티셔츠의 색을 마스크/바지와 겹치지 않게 하고 같은 색 티셔츠를 연속으로 입지 않을 때, 입을 수 있는 가장 긴 일수 구하기