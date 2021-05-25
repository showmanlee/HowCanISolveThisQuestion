// 와글와글 숭고한
// https://www.acmicpc.net/problem/17388

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int s, g, h;
	cin >> s >> g >> h;
	if (s + g + h >= 100)
		cout << "OK";
	else {
		int m = min({ s, g, h });
		if (m == s)
			cout << "Soongsil";
		else if (m == g)
			cout << "Korea";
		else if (m == h)
			cout << "Hanyang";
	}
	cout << '\n';
}

// 숭실대, 고려대, 한양대의 참여도가 주어졌을 때, 세 대학의 참여도의 합이 100 이상이면 OK, 그렇지 않다면 가장 작은 참여도를 가진 대학 출력하기

// algorithm의 max/min 함수에 중괄호 배열을 넣으면 3개 이상의 수를 한 번에 비교할 수 있다
// 앞으로 잘 써먹어야지