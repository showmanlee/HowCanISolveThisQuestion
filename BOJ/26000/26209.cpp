// Intercepting Information
// https://www.acmicpc.net/problem/26209

#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	bool pass = true;
	for (int i = 0; i < 8; i++) {
		int p;
		cin >> p;
		if (p == 9) {
			pass = false;
		}
	}
	cout << (pass ? "S" : "F") << '\n';
}

// 주어진 세 수를 정렬했을 때 가운데에 있는 수 구하기

// 네 구할게요