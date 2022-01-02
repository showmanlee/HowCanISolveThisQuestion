// 나는 학급회장이다
// https://www.acmicpc.net/problem/2456

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
typedef tuple<int, int, int, int, int> tpi4;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<tpi4> ranks(3);
	for (int i = 0; i < 3; i++)
		get<4>(ranks[i]) = i + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int p;
			cin >> p;
			get<0>(ranks[j]) += p;
			if (p == 3)
				get<1>(ranks[j])++;
			if (p == 2)
				get<2>(ranks[j])++;
			if (p == 1)
				get<3>(ranks[j])++;
		}
	}
	sort(ranks.begin(), ranks.end());
	if (get<0>(ranks[2]) != get<0>(ranks[1]))
		cout << get<4>(ranks[2]) << ' ' << get<0>(ranks[2]) <<  '\n';
	else {
		if (get<1>(ranks[2]) != get<1>(ranks[1]))
			cout << get<4>(ranks[2]) << ' ' << get<0>(ranks[2]) << '\n';
		else {
			if (get<2>(ranks[2]) != get<2>(ranks[1]))
				cout << get<4>(ranks[2]) << ' ' << get<0>(ranks[2]) << '\n';
			else
				cout << 0 << ' ' << get<0>(ranks[2]) << '\n';
		}
	}
}

// 3명의 후보가 나온 선거에서 유권자들이 각 후보에게 1/2/3점을 한 번씩만 줄 수 있을 때, 투표 결과는 총점 순, 동률이 나오면 3점을 받은 순, 동률이 나오면 2점을 받은 순, 동률이 나오면 무효화된다
// 이때, 투표 결과와 결과에 관계없이 한 후보가 얻은 최다 점수 출력하기

// 총점, 3점, 2점, 1점, 내 번호를 하나의 튜플로 묶어서 내림차순으로 정렬하기
// 이후 1등과 2등의 총점 -> 3점 -> 2점이 차이나는지 확인하고, 끝까지 차이가 안 나면 0, 아니면 1등 번호 출력하기