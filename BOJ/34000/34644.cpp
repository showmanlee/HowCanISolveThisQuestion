// Ten Player Bingo
// https://www.acmicpc.net/problem/34644

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(100);
	for (int i = 0; i < 100; i++) {
		cin >> v[i];
	}
	cout << (v[99] % 10 == 0 ? 10 : v[99] % 10) << '\n';
}

// 1부터 100까지 무작위로 불러 마지막으로 지워지는 1의 자리 구하기