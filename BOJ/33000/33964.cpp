// 레퓨닛의 덧셈
// https://www.acmicpc.net/problem/33964

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	int aa = 0, bb = 0;
	for (int i = 0; i < a; i++) {
		aa *= 10;
		aa += 1;
	}
	for (int i = 0; i < b; i++) {
		bb *= 10;
		bb += 1;
	}
	cout << (aa + bb) << '\n';
}

// 1이 각각 a, b개 있는 자연수 더하기