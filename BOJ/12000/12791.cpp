// Starman
// https://www.acmicpc.net/problem/12791

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, string> prs;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	vector<prs> dict = {
		{1967, "DavidBowie"},
		{1969, "SpaceOddity"},
		{1970, "TheManWhoSoldTheWorld"},
		{1971, "HunkyDory"},
		{1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
		{1973, "AladdinSane"},
		{1973, "PinUps"},
		{1974, "DiamondDogs"},
		{1975, "YoungAmericans"},
		{1976, "StationToStation"},
		{1977, "Low"},
		{1977, "Heroes"},
		{1979, "Lodger"},
		{1980, "ScaryMonstersAndSuperCreeps"},
		{1983, "LetsDance"},
		{1984, "Tonight"},
		{1987, "NeverLetMeDown"},
		{1993, "BlackTieWhiteNoise"},
		{1995, "1.Outside"},
		{1997, "Earthling"},
		{1999, "Hours"},
		{2002, "Heathen"},
		{2003, "Reality"},
		{2013, "TheNextDay"},
		{2016, "BlackStar"}
	};

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int x, y;
		cin >> x >> y;
		vector<prs> res;
		for (auto& p : dict) {
			if (p.first >= x && p.first <= y) {
				res.push_back(p);
			}
		}
		cout << res.size() << '\n';
		for (auto& p : res) {
			cout << p.first << ' ' << p.second << '\n';
		}
	}
}

// 데이빗 보위의 앨범 발매 연도과 제목이 주어질 때, 주어진 연도 범위에 발매된 앨범의 출시 연도와 날짜 출력하기

// 연도와 앨범명을 pair로 저장한 후, 범위를 보고 해당되는 요소들을 다른 배열로 옮겨 그 크기를 출력하고 요소를 출력한다