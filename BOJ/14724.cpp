// 관리자는 누구?
// https://www.acmicpc.net/problem/14724

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string names[9] = { "PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY" };
	vector<int> counts(9);
	int n;
	cin >> n;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < n; j++) {
			int p;
			cin >> p;
			if (counts[i] < p)
				counts[i] = p;
		}
	}
	int res = 0;
	for (int i = 0; i < 9; i++)
		if (counts[res] < counts[i])
			res = i;
	cout << names[res] << '\n';
}

// 각각의 이름을 가지고 있는 9개의 동아리에서 동아리 당 n명의 점수가 주어질 때, 전체 동아리에서 가장 높은 점수를 가진 사람이 속한 동아리 출력하기
// 각 동아리 안에서 최댓값을 구하고, 동아리 간의 최댓값 구하기
// 전자는 값으로, 후자는 인덱스로 판정하여 동아리 이름 출력되게 하기