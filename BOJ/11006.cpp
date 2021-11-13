// 남욱이의 닭장
// https://www.acmicpc.net/problem/11006

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
		int normal = a - b;
		cout << (b - normal) << ' ' << normal << '\n';
	}
}

// 모든 닭의 다리 수와 개체 수가 주어졌을 때, 다리가 하나만 있는 닭과 모두 있는 닭의 개수 구하기

// 우선 모든 닭이 다리 하나를 가지고 있으니 다리 수에서 개체 수를 빼서 남은 다리는 멀쩡한 닭들이 가지고 있는 것
// 따라서 남은 다리 수가 곧 멀쩡한 개체 수고, 나머지가 비정상 개체