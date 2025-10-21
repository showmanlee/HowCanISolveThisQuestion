// 와우산 스탬프 투어
// https://www.acmicpc.net/problem/34543

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<string, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	int res = a * 10;
	if (a >= 3) {
		res += 20;
	}
	if (a == 5) {
		res += 50;
	}
	if (b > 1000) {
		res = max(0, res - 15);
	}
	cout << res << '\n';
}

// 문제에서 주어지는 대로 점수 산정하기