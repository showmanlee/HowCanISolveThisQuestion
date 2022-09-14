// Schronisko
// https://www.acmicpc.net/problem/8760

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cout << (a * b / 2) << '\n';
	}
}

// a*b 보드에 2칸씩 차지하는 사람을 넣을 때, 들일 수 있는 사람의 수는?

// a * b / 2에서 소수 버림