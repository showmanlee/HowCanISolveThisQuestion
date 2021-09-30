// No Brainer
// https://www.acmicpc.net/problem/4562

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int a, b;
		cin >> a >> b;
		if (a >= b)
			cout << "MMM BRAINS\n";
		else
			cout << "NO BRAINS\n";
	}
}

// 좀비가 먹은 뇌의 개수와 필요한 개수가 주어졌을 때, 좀비가 뇌를 충분히 먹었는지 판정하기

// 그냥 대소관계에 따라 결과 출력하는 문제.