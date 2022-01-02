// 농구 경기
// https://www.acmicpc.net/problem/1159

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> cnt(26);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cnt[s[0] - 'a']++;
	}
	bool res = false;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 5) {
			res = true;
			cout << char(i + 'a');
		}
	}
	if (!res)
		cout << "PREDAJA";
	cout << '\n';
}

// 소문자로 구성된 성들 중 첫 글자가 5번 이상 나온 경우들 찾기

// 각 알파벳별로 등장 횟수를 담는 배열을 이용해 카운팅 - 문자열을 받아 그 중 첫 문자만 보고 카운팅
// 이후 해당 배열을 돌면서 5 이상인 것을 발견하면 해당 인덱스를 이용해 글자 출력 - 그러면서 결과가 있음을 별도의 변수에 표시
// 만약 결과가 없으면 PREDAJA 출력