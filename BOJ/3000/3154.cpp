// 알람시계
// https://www.acmicpc.net/problem/3154

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	vector<pr> coord = {
		{3, 1},
		{0, 0},
		{0, 1},
		{0, 2},
		{1, 0},
		{1, 1},
		{1, 2},
		{2, 0},
		{2, 1},
		{2, 2},
	};
	string s;
	cin >> s;
	int h = (s[0] - '0') * 10 + (s[1] - '0');
	int m = (s[3] - '0') * 10 + (s[4] - '0');
	int resh = 0, resm = 0, res = 987654321;
	for (int hh = h; hh < 100; hh += 24) {
		for (int mm = m; mm < 100; mm += 60) {
			int r = abs(coord[hh / 10].first - coord[hh % 10].first) + abs(coord[hh / 10].second - coord[hh % 10].second)
			+ abs(coord[hh % 10].first - coord[mm / 10].first) + abs(coord[hh % 10].second - coord[mm / 10].second)
			+ abs(coord[mm / 10].first - coord[mm % 10].first) + abs(coord[mm / 10].second - coord[mm % 10].second);
			if (r < res) {
				res = r;
				resh = hh;
				resm = mm;
			}
		}
	}
	cout.width(2);
	cout.fill('0');
	cout << resh << ":";
	cout.width(2);
	cout.fill('0');
	cout << resm << '\n';
}

// 키패드로 시각을 입력하는 시계에서 시/분에 적힌 수를 각각 24/60으로 나눈 나머지로 인식할 때, 주어진 시각을 입력하는데 필요한 버튼 입력간 거리가 가장 짧은 입력 결과 출력하기

// 주어진 시각(~23:59)를 받고, 여기서 나머지 연산을 했을 때 동일한 결과들을 구해 거리를 재보고 결과를 구한다