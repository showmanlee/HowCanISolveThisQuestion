// Máquina de café
// https://www.acmicpc.net/problem/15051

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	cout << min(a * 2 + c * 2, min(a * 4 + b * 2, c * 4 + b * 2)) << '\n';
}

// 각 층마다 일하는 직원 수가 다른 3층 건물 중 한 층에 커피머신을 놓을 때, 직원들이 커피를 마시기 위해 층계를 오르내리는 횟수가 가장 작은 경우는?

// 한 층을 오르거나 내릴 때 1분이 걸린다 - 한 층 차이 나면 인원수 * 2, 두 층 차이는 인원수 * 4가 누적된다는 의미
// 이를 고려해 1/2/3층에 놓을 때 생기는 각 경우의 수를 보고 가장 작은 경우를 선택하면 됨