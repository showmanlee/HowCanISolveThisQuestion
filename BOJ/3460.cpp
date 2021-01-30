// 이진수
// https://www.acmicpc.net/problem/3460

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		int cnt = 0;
		while (n > 0) {
			if (n % 2 == 1)
				cout << cnt << ' ';
			n /= 2;
			cnt++;
		}
		cout << '\n';
	}
}

// 십진수를 이진수로 바꿀 때 1의 위치는?
// 2로 나눌 때마다 앞자리로 이동