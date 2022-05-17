// 치킨댄스를 추는 곰곰이를 본 임스
// https://www.acmicpc.net/problem/25191

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b;
	cin >> n >> a >> b;
	cout << min(n, a / 2 + b) << '\n';
}

// 치킨집에 치킨이 n마리 있는데 반드시 콜라 2병 또는 맥주 1병과 함께 치킨을 1마리 먹을 수 있을 때, 먹을 수 있는 치킨의 최대 수는?

// 콜라 수 / 2 + 맥주 수만큼 먹을 수 있는데, 치킨이 품절되면 안 됨
// 따라서 이를 계산해서 출력해줍니다