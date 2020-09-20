// 별 찍기 - 10
// https://www.acmicpc.net/problem/2447

#include <iostream>
#include <vector>

using namespace std;
int arr[2190][2190];	// 최대치 = 3^7

void star(int n, int x, int y) {
	if (n == 1) {
		arr[x][y] = 1;
		return;
	}
	int center = n / 3; 
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (!(i == 1 && j == 1))
				star(center, x + center * i, y + center * j);
}

int main(void) {
	int n;
	cin >> n;
	star(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << (arr[i][j] ? "*" : " ");
		cout << endl;
	}
}

// 꼭 바로 찍을 필요 있나? 배열에 저장해서 찍으면 되지
// 이게 바로 분할 정복