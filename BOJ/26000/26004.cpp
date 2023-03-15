// HI-ARC
// https://www.acmicpc.net/problem/26004

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v(26, 987654321);
	v[0] = v[2] = v[7] = v[8] = v[17] = 0;
	for (char c : s) {
		v[c - 'A']++;
	}
	int res = 987654321;
	for (int i = 0; i < 26; i++) {
		res = min(res, v[i]);
	}
	cout << res << '\n';
}

// 주어진 대문자 문자열에서 H, I, A, R, C 쌍의 개수 구하기

// 이 다섯 글자 중 가장 적게 등장하는 개수 찾기
// 각 글자의 카운터를 만드는 것도 좋지만, 그냥 26칸 배열을 만들어서 목표만 0, 나머지는 모두 MAX값을 채운 후 min을 돌려도 됨