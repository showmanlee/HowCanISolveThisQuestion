// 지우개
// https://www.acmicpc.net/problem/21756

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<bool> checker(n + 1);
	int remain = n;
	while (remain != 1) {
		int idx = 0;
		for (int i = 1; i <= n; i++) {
			if (!checker[i]) {
				idx++;
				if (idx % 2 == 1) {
					checker[i] = true;
					remain--;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (!checker[i])
			cout << i << '\n';
}

// 1부터 n까지 적힌 배열에서 매 홀수 칸을 지우고 왼쪽으로 모으는 과정을 반복할 때, 마지막으로 남게 되는 수는?

// 배열에서 실제로 지우고 모으지 말고, 살아있는 인덱스를 표시하는 배열을 만들어 활용하자
// 남아있는 수를 기록하는 remain을 통해 남은 수가 하나만 남을 때까지 배열 전체를 순회한다
// 만약 아직 지워지지 않은 수를 발견한 경우 인덱스를 1 올리고, 그 결과가 홀수인 경우 해당 수를 지운다
// 최종적으로 수가 하나 남았을 때 배열을 돌려 남은 수를 발견하고 출력하기