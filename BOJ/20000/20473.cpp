// Гостиница	
// https://www.acmicpc.net/problem/20473

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int two = 0, three = 0;
	while (n > 0) {
		if (n == 4) {
			two += 2;
			n -= 4;
		} else if (n == 2) {
			two += 1;
			n -= 2;
		} else {
			three++;
			n -= 3;
		}
	}
	cout << two << ' ' << three << '\n';
}

// 주어진 인원수를 인원수에 맞게 채울 수 있는 2인실과 3인실의 개수 구하기