// 타임머신
// https://www.acmicpc.net/problem/1440

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int a = (s[0] - '0') * 10 + (s[1] - '0');
	int b = (s[3] - '0') * 10 + (s[4] - '0');
	int c = (s[6] - '0') * 10 + (s[7] - '0');

	vector<int> v = {0, 1, 2};
	vector<pr> range = {{1, 12}, {0, 59}, {0, 59}};
	int res = 0;
	do {
		if (a >= range[v[0]].first && a <= range[v[0]].second && b >= range[v[1]].first && b <= range[v[1]].second && c >= range[v[2]].first && c <= range[v[2]].second) {
			res++;
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << res << '\n';
}

// 시각 표기가 주어질 때, 읽을 수 있는 방법의 수 구하기

// 자리를 순열로 세팅한 후, 그 자리의 수들이 각각의 범위를 만족하는지 판정하기