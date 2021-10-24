// 점수 집계
// https://www.acmicpc.net/problem/9076

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int sum = 0;
		vector<int> v(5);
		for (int i = 0; i < 5; i++) {
			cin >> v[i];
			sum += v[i];
		}
		sort(v.begin(), v.end());
		sum -= v[0] + v[4];
		if (v[3] - v[1] >= 4) {
			cout << "KIN\n";
		}
		else {
			cout << sum << '\n';
		}
	}
}

// 5개의 점수 중 최고점과 최저점을 빼서 최종 점수를 구하는 과정에서 남은 점수 중 최고점과 최저점의 차가 4 이상이면 KIN 판정을 내릴 때, 최종 판정 or 점수 출력하기

// 5개의 점수를 배열로 받아 정렬한다 - 이후 총합에서 최고점과 최저점을 빼둔다
// 이후 1번과 3번의 차를 보고 4 이상이면 KIN, 아니라면 총합 출력