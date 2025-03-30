// SUAPC 2023 Summer
// https://www.acmicpc.net/problem/31429

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	pr v[12] = {
		{0, 0},
		{12, 1600},
		{11, 894},
		{11, 1327},
		{10, 1311},
		{9, 1004},
		{9, 1178},
		{9, 1357},
		{8, 837},
		{7, 1055},
		{6, 556},
		{6, 773}
	};

	int n;
	cin >> n;
	cout << v[n].first << ' ' << v[n].second << '\n';
}

// 주어진 정수 배열에서 순서를 그대로 유지하면서 오름차순이 되도록 원소 빼서 출력하기