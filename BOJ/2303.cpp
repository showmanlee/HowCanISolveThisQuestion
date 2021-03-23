// 숫자 게임
// https://www.acmicpc.net/problem/2303

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int combi(vector<int> cards, int i, int c, int sum) {
	if (c == 3)
		return sum % 10;
	int ret = 0;
	for (int j = i; j < 5; j++)
		ret = max(ret, combi(cards, j + 1, c + 1, sum + cards[j]));
	return ret;
}

int main(void) {
	int n;
	cin >> n;
	int maxx = 0, res = 0;
	for (int i = 1; i <= n; i++) {
		vector<int> cards(5);
		for (int& j : cards)
			cin >> j;
		int t = combi(cards, 0, 0, 0);
		if (t >= maxx) {
			maxx = t;
			res = i;
		}
	}
	cout << res << '\n';
}

// 5장의 숫자 카드 중 세 장을 골라 그 합의 일의 자리 수를 최대로 만드는 사람이 이길 때, 승자는?
// 재귀함수를 통한 5C3 n명 반복 - 배열을 인수로 주면 값을 저장하는 배열을 만들지 않아도 됨
// 동률이 나온 경우 번호가 가장 큰 사람으로 갱신하기