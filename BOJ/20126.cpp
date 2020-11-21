// 교수님의 기말고사
// https://www.acmicpc.net/problem/20126

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	int n, m, s;
	cin >> n >> m >> s;
	vector<pr> lect(n + 1);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		lect[i].first = x;
		lect[i].second = x + y;
	}
	lect[n].first = lect[n].second = s;
	sort(lect.begin(), lect.end());

	int res = -1;
	for (int i = 0; i < n; i++) {
		if (lect[i + 1].first - lect[i].second >= m) {
			res = lect[i].second;
			break;
		}
	}
	if (lect[0].first >= m)
		res = 0;
	cout << res << '\n';
}

// 입력값(시작 / 지속시간)을 pair(시작 / 종료)로 바꾸어 n+1칸 배열에 넣고 정렬, 마지막칸에는 종료 시간 s 넣기
// 이후 0~n-1까지 순회하며 내 시간의 끝과 다음 시간 시작의 차가 쓰고 싶은 시간 이상이라면 해당 시간에 들어가기
// 그리고 맨 마지막에 첫 번째 시간이 비었는지 확인하기