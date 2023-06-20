// 카트라이더: 드리프트
// https://www.acmicpc.net/problem/27522

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<string, string> pr;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	vector<pr> v(8);
	for (int i = 0; i < 8; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	vector<int> points = {10, 8, 6, 5, 4, 3, 2, 1};
	int r = 0, b = 0;
	for (int i = 0; i < 8; i++) {
		if (v[i].second == "B") {
			b += points[i];
		} else {
			r += points[i];
		}
	}
	cout << (r > b ? "Red" : "Blue") << '\n';
}

// 카트라이더: 드리프트 스피드 팀전에서 완주 현황이 주어졌을 때, 승리 팀 구하기

// 모든 레이서는 다른 시간에 완주하고(동기록/점수 없음), 모두 리타이어하지 않음이 보장됨
// 시간이 M:SS:sss 형태로 주어지긴 하지만, 이걸 굳이 파싱할 필요는 없음 - 어차피 시간 순으로 정렬이 될 테니까
// 따라서 팀명과 함께 시간 순으로 정렬을 한 다음, 정렬한 순서대로 돌면서 팀 점수를 매겨 승리 팀을 구한다