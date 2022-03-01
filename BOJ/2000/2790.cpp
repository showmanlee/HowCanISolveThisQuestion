// F7
// https://www.acmicpc.net/problem/2790

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> score(n);
	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}
	sort(score.begin(), score.end(), greater<int>());
	int maxx = score[0] + 1;
	int res = 1;
	for (int i = 1; i < n; i++) {
		if (score[i] + n >= maxx) {
			res++;
		}
		maxx = max(maxx, score[i] + i + 1);
	}
	cout << res << '\n';
}

// n명이 참가하는 대회에서 한 라운드의 결과에 따라 n~1점을 얻을 때, 마지막 라운드 시점의 점수를 보고 우승 가능성이 있는 사람의 수는(공동 우승 가능)?

// 우승 가능성이 가장 높은 사람이 최소점을 얻은 상태에서 자신이 최고점을 받았을 때 1등이라면 우승 가능성이 있는 선수
// 우선 점수들을 역순으로 정렬 - 여기서 1등은 무조건 우승할 수 있음
// 이후에는 순서대로 돌며 현재 점수에서 1등한 점수가 지금까지 나온 점수 중 꼴등 + 누적 순위보다 클 경우 우승 가능성이 있다는 의미