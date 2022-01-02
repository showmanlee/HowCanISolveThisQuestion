// 골뱅이 찍기 - 정사각형
// https://www.acmicpc.net/problem/23794

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n + 2; i++) {
		for (int j = 1; j <= n + 2; j++) {
			cout << (i == 1 || i == n + 2 || j == 1 || j == n + 2 ? '@' : ' ');
		}
		cout << '\n';
	}
}

// 한 변이 n + 2인 정사각형 그리기

// 그리면 됩니다 - 어떤 한 축의 좌표가 끝점에 걸쳐있다면 찍기!