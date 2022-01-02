// 자석 체인
// https://www.acmicpc.net/problem/17201

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;
	bool res = true;
	for (int i = 1; i < n * 2; i++)
		if (s[i] == s[i - 1])
			res = false;
	cout << (res ? "Yes" : "No") << '\n';
}

// 자석들의 극성 배치가 주어졌을 때, 자석들이 모두 붙어있는 상태인지 판별하기
// 극성이 121212... 또는 212121이어야지 모두 붙어있음
// 그러니까 자석 배열에서 내 옆의 극이 같으면 무조건 아웃
// 애초에 막대자석 단위로 주어지는 것 - 그러나 그냥 문자열로 봐도 잘 풀림