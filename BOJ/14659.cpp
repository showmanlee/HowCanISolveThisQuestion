// 한조서열정리하고옴ㅋㅋ
// https://www.acmicpc.net/problem/14659

#include <iostream>
using namespace std;

int main(void) {
	int n;
	int res = 0, count = 0, cur = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p > cur) {
			cur = p;
			if (count > res)
				res = count;
			count = 0;
		}
		else
			count++;
	}
	if (count > res)
		res = count;
	cout << res << '\n';
}

// 오른쪽으로 빌딩 볼때 보이는 높이 구하는 문제와 같음
// 오른쪽으로 밀고 가면서 작으면 카운트 높이고, 크면 카운트 초기화하여 최대치 구하기
// vector를 안 써도 될듯