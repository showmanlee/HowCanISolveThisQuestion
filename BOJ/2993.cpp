// 세 부분
// https://www.acmicpc.net/problem/2993

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;
int n;
vector<string> res;

void split(int p, int a, int b) {
	if (a != -1 && b != -1) {
		string sp[3] = { s.substr(0, a), s.substr(a, b - a), s.substr(b) };
		string ret;
		for (int t = 0; t < 3; t++) {
			for (int i = sp[t].length() - 1; i >= 0; i--)
				ret += sp[t][i];
		}
		res.push_back(ret);
		return;
	}
	for (int i = p + 1; i < n; i++) {
		if (a == -1)
			split(i, i, b);
		else
			split(i, a, i);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;
	n = s.length();
	split(0, -1, -1);
	sort(res.begin(), res.end());
	cout << res[0] << '\n';
}

// 한 문자열을 세 부분으로 나누어 각 부분의 문자 위치를 뒤집고 다시 붙인 문자열 중 사전 상 가장 앞에 위치하는 문자열은?
// 문자열을 받고, 재귀 함수를 돌려 문자열을 나눌 경계 두 곳을 정해준다 - 1부터 n - 1까지 한 글자는 남을 수 있도록
// 이후 각 경계별로 문자열을 나누고 이를 뒤집어서 붙인 값을 새 문자열에 넣어준 뒤 이를 결과 배열에 삽입
// 마지막으로 해당 배열을 정렬 후 첫 번째로 나오는 문자열을 확인하면 끝

// 1251과 같은 문제