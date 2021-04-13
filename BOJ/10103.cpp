// 주사위 게임
// https://www.acmicpc.net/problem/10103

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int a = 100, b = 100;
	for (int i = 0; i < n; i++) {
		int p, q;
		cin >> p >> q;
		if (p > q)
			b -= p;
		else if (p < q)
			a -= q;
	}
	cout << a << '\n' << b << '\n';
}

// 서로 100점씩 가진 상태에서 동시에 주사위를 굴려 낮은 쪽이 나온 사람이 높은 사람의 주사위 눈 수만큼 점수를 깎는다고 할 때, 최종 결과는?
// 게임이 최대 15판까지 진행되므로 음수는 고려할 필요 없음
// 조건따라 점수 빼주기 반복