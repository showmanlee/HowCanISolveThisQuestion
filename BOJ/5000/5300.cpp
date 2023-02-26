// Fill the Rowboats!
// https://www.acmicpc.net/problem/5300

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << i << ' ';
		if (i % 6 == 0 && i != n) {
			cout << "Go! ";
		}
	}
	cout << "Go!";
}

// 1부터 n까지 출력하면서 6의 배수나 n일 때 Go! 출력하기

// 시키는대로 합시다...