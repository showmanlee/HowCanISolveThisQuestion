// 성적 통계
// https://www.acmicpc.net/problem/5800

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int n;
		cin >> n;
		vector<int> scores(n);
		for (int j = 0; j < n; j++)
			cin >> scores[j];
		sort(scores.begin(), scores.end());
		int diff = 0;
		for (int j = 0; j < n - 1; j++)
			if (scores[j + 1] - scores[j] > diff)
				diff = scores[j + 1] - scores[j];
		cout << "Class " << i << '\n';
		cout << "Max " << scores[n - 1] << ", Min " << scores[0] << ", Largest gap " << diff << '\n';
	}
}

// 한 반의 최고 점수, 최저 점수, 그리고 인접한 등위의 최대 점수 차 구하기
// 정렬 후 최대 점수 차만 순회하며 구하면 완료