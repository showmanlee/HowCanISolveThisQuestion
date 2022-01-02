// 주사위
// https://www.acmicpc.net/problem/9295

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int a, b;
		cin >> a >> b;
		cout << "Case " << t << ": " << (a + b) << '\n';
	}
}

// 주사위 두 눈의 합은?
// 세보면 되지