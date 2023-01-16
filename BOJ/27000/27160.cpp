// 할리갈리
// https://www.acmicpc.net/problem/27160

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> cnt(4);
	string board[4] = {"STRAWBERRY", "BANANA", "LIME", "PLUM"};
	for (int i = 0; i < n; i++) {
		string s;
		int p;
		cin >> s >> p;
		for (int j = 0; j < 4; j++) {
			if (s == board[j]) {
				cnt[j] += p;
			}
		}
	}
	bool res = false;
	for (int i = 0; i < 4; i++) {
		if (cnt[i] == 5) {
			res = true;
		}
	}
	cout << (res ? "YES" : "NO") << '\n';
}
 
// 할리갈리에서 나온 카드 리스트가 주어졌을 때, 종을 눌러아햐는지 판정하기

// 한 과일이 정확히 5개 있는지 확인하기
// 문자열을 배열 인덱스로 적절히 바꿔서 과일 개수를 세고, 다시 과일별 갸수를 세서 5개인 경우가 있으면 종 치기