// 이진 딸기
// https://www.acmicpc.net/problem/22935

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		n--;
		n %= 28;
		n++;
		if (n > 15)
			n = 30 - n;
		int p = 8;
		for (int i = 0; i < 4; i++) {
			if (n >= p) {
				cout << "딸기";
				n -= p;
			}
			else
				cout << "V";
			p /= 2;
		}
		cout << '\n';
	}
}

// 어떤 숫자를 외치면 1~15~1 레인지로 변환하여 딸기를 이진수 형태로 외쳐야 하는 딸기 게임에서 외치는 방법은?

// 1에서 15까지 올라가고, 16부터는 다시 14부터 아래로 내려가 29에서 다시 1을 찍는다
// 여기서 1과 15는 정점이기에 한 번만 찍는다 - 따라서 루프의 폭은 28
// 편한 계산을 통해 주어진 수에서 1을 빼서 28을 나머지 연산한 후 다시 1을 더한다 - 1부터 28까지 형태로 주어짐
// 내려가는 수의 원래 위치를 잡으려면 30에서 빼주면 됨 - 30 - 16 = 14, 30 - 28 = 2 (30 - 29 = 1)
// 이렇게 얻은 위치값을 이용해 V를 0, 딸기를 1 삼아 이진수로 변환하여 출력하기