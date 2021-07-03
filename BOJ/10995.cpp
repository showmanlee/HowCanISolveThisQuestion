// 별 찍기 - 20
// https://www.acmicpc.net/problem/10995

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			if (i % 2 == j % 2)
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
}

// 주어진 형식대로 별 찍기

// n*2n 보드에서 가로로 한 칸 간격으로 별을 찍는데 홀수 줄과 짝수 줄의 별이 서로 어긋나 있어야 한다
// 이는 i % 2와 j % 2 값을 확인 가능 - 둘다 0으로 시작했다면 i % 2 == j % 2일 때 별을 찍기