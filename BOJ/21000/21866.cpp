// 추첨을 통해 커피를 받자
// https://www.acmicpc.net/problem/21866

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> scores(9);
	for (int i = 0; i < 9; i++)
		cin >> scores[i];
	bool hacker = false;
	int res = 0;
	for (int i = 0; i < 9; i++) {
		res += scores[i];
		if (scores[i] > 100 * (i / 2 + 1))
			hacker = true;
	}
	if (hacker)
		cout << "hacker";
	else
		cout << (res >= 100 ? "draw" : "none");
	cout << '\n';
}

// 각각의 최대 점수가 100점, 100점, 200점, 200점, 300점, 300점, 400점, 400점, 500점인 9문제를 풀어 점수의 총 합이 100점 이상이면 커피를 주려고 하는데, 문제 중 한 문제라도 최대 점수를 넘겼다면 해커로 규정하고자 한다
// 이때, 커피 지급 대상 및 해커 판정하기

// 각 점수를 배열에 담아 합을 구하면서 각 칸에 대응하는 최대 점수 초과 여부 판별하기
// 판정은 해커가 우선(해커가 되면 무조건 커피 지급)