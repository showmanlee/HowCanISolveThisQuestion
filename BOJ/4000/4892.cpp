// 숫자 맞추기 게임
// https://www.acmicpc.net/problem/4892

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int cnt = 0;
	while (true) {
		cnt++;
		int p;
		cin >> p;
		if (p == 0) {
			break;
		}
		cout << cnt << ". ";
		bool r = p * 3 % 2;
		cout << (r ? "odd " : "even ");
		if (r) {
			p -= 1;
		}
		p /= 2;
		cout << p << '\n';
	}
}

// n0이 주어질 때, n1 = 3 * n0, n2 = (n1 + (n1 % 2 ? 1 : 0)) / 2, n3 = 3 * n2, n4 = n3/9인 수 변환 과정에서 n1의 홀짝 여부와 n4 출력하기

// 이걸 그대로 돌려봐도 되지만, 이거에 대한 축약 버전이 문제에 나와있기에 이를 이용해 구할 수 있음