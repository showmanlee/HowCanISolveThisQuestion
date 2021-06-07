// 적어도 대부분의 배수
// https://www.acmicpc.net/problem/1145

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(5);
	for (int i = 0; i < 5; i++)
		cin >> v[i];
	int res = 0, n = 1;
	while (true) {
		int p = 0;
		for (int i = 0; i < 5; i++)
			if (n % v[i] == 0)
				p++;
		if (p >= 3) {
			res = n;
			break;
		}
		n++;
	}
	cout << res << '\n';
}

// 5개의 자연수 중 3개 이상의 수로 나누어떨어지는 수 중 가장 작은 수는?

// 자연수가 최대 100까지만 주어지므로 브포 안에서 판정 가능 - 자연수 5개와 연산해보고 나누어떨어지는 수가 3개 이상이 되면 바로 출력