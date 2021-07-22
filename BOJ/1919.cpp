// 애너그램 만들기
// https://www.acmicpc.net/problem/1919

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> cnt(26);
	string a, b;
	cin >> a >> b;
	for (char c : a)
		cnt[c - 'a']++;
	for (char c : b)
		cnt[c - 'a']--;
	int res = 0;
	for (int i = 0; i < 26; i++)
		res += abs(cnt[i]);
	cout << res << '\n';
}

// 두 소문자 문자열을 애너그램 관계로 만들기 위해 지워야 하는 문자의 수는?

// 두 개의 문자열을 순회하며 각 문자의 개수를 세주는데, 첫 번째 문자열은 발견시 더해주고, 두 번째 문자열은 빼준다
// 이렇게 돌린 결과 문자의 개수가 0이 되면 해당 문자는 지울 필요가 없다는 것 - 만약 0이 아니라면 절댓값만큼 문자를 빼줘야 함을 의미