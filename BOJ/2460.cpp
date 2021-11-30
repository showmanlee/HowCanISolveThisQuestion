// 지능형 기차 2
// https://www.acmicpc.net/problem/2460

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int res = 0;
	int train = 0;
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		train += -a + b;
		res = max(res, train);
	}
	cout << res << '\n';
}

// 10개의 역마다 기차에서 내리고 탄 사람의 수가 주어졌을 때, 기차에 가장 많은 사람이 타고 있었던 순간의 인원수는?

// 10개의 역을 다니면서 내리고 태우며 총 인원을 구한 후, 그 중 최댓값을 답으로 출력하기
// 내리는 경우에는 어떻게든 최댓값이 될 수 없으므로 탔을 때만 판정하기