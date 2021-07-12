// 가장 큰 금민수
// https://www.acmicpc.net/problem/1526

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n >= 4) {
		int p = n;
		bool valid = true;
		while (p != 0) {
			if (p % 10 != 4 && p % 10 != 7) {
				valid = false;
				break;
			}
			p /= 10;
		}
		if (valid)
			break;
		n--;
	}
	cout << n << '\n';
}

// 4와 7로만 이루어진 수 중 주어진 수보다 작거나 같은 수 찾기

// n부터 시작하여 각 자릿수에 4와 7만 등장하는지 확인하고, 찾는 수가 아니라면 하나씩 줄여간다
// 그러다가 수를 찾으면 출력하기