// Trident
// https://www.acmicpc.net/problem/6903

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, s, h;
	cin >> t >> s >> h;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 3 + s * 2; j++) {
			if (j == 0 || j == 2 + s * 2 || j == 1 + s) {
				cout << '*';
			} else {
				cout << ' ';
			}
		}
		cout << '\n';
	}
	for (int j = 0; j < 3 + s * 2; j++) {
		cout << '*';
	}
	cout << '\n';
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < 1 + s; j++) {
			cout << ' ';
		}
		cout << "*\n";
	}
}

// 꼭지 길이가 t, 꼭지 사이 거리가 s, 손잡이 길이가 h인 삼지창 그리기

// 그리면 됩니다 - 별찍기의 아종