// 스물셋
// https://www.acmicpc.net/problem/23251

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		cout << (n * 23) << '\n';
	}
}

// 23으로 이루어진 수와 그들의 합으로 나타낼 수 있는 수 중 n번째로 작은 수는?

// 23으로 이루어진 수는 23, 2323, 232323... 등 - 2와 3으로 구성된 수가 아님
// 2323 = 23*101 - 따라서 23으로 이루어진 수는 그들의 합 안에 포함됨
// 따라서 n번째로 작은 수는 23*n으로 볼 수 있고, 실제로도 그러함