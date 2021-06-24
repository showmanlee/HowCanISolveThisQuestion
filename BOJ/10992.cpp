// 별 찍기 - 17
// https://www.acmicpc.net/problem/10992

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++)
			cout << ' ';
		for (int j = 0; j < i * 2 + 1; j++) {
			if (j == 0 || j == i * 2)
				cout << '*';
			else
				cout << (i == n - 1 ? '*' : ' ');
		}
		cout << '\n';
	}
}

// 정삼각형으로 점 찍기

// ㅅ 찍기와 동일하지만, 마지막줄에는 별과 별 사이 공간을 모두 채워야 함