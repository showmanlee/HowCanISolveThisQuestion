// Triangles
// https://www.acmicpc.net/problem/5356

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
		char c;
		cin >> n >> c;
		for (int i = 0; i < n; i++) {
			char cc = (c - 'A' + i) % 26 + 'A';
			for (int j = 0; j <= i; j++) {
				cout << cc;
			}
			cout << '\n';
		}
		if (t < tt - 1) {
			cout << '\n';
		}
	}
}

// 각 줄이 c부터 시작해 한 글자씩 순환하는 대문자로 구성된 길이 n의 직각삼각형 찍기

// 예제 보고 똑같이 찍어주기 - 조금 고급스러운 별 찍기