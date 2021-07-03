// 동일한 단어 그룹화하기
// https://www.acmicpc.net/problem/16499

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	set<string> res;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		res.insert(s);
	}
	cout << res.size() << '\n';
}

// 소문자로 구성된 단어 중 같은 알파벳으로 구성된 단어를 그룹한 후 남은 그룹의 수 구하기

// 문자열을 받고 정렬한다 - 정렬하면 같은 알파벳으로 구성된 단어는 동일한 형태를 띄게 됨
// 이렇게 만든 문자열을 set에 넣고, 모든 문자열을 넣은 뒤 set의 크기를 구하면 그게 답

// BOJ 1000문제 돌파(번외 포함)!!! - 10개월 간의 노력이 여기까지 다다릅니다
// 다음 큰 목표는 solved.ac 레이팅 2000 돌파와 BOJ 1페이지(2000문제)!