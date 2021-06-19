// 뒤집기
// https://www.acmicpc.net/problem/1439

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int zero = 0, one = 0;
	if (s[0] == '0')
		zero++;
	else
		one++;
	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] != s[i]) {
			if (s[i] == '0')
				zero++;
			else
				one++;
		}
	}
	int res = min(zero, one);
	cout << res << '\n';
}

// 0과 1로 구성된 문자열에서 특정 범위를 지정해 해당 숫자들을 뒤집을 수 있을 때, 문자열의 모든 숫자를 하나의 숫자로 통일시키기 위해 필요한 최소 뒤집기 수는?

// 같은 숫자들이 뭉친 덩어리끼리 뒤집어주는 것이 이득 - 0101010에서 같은 숫자가 있는 양끝점들을 하나씩 뒤집는 것과 1만 집어서 뒤집는 횟수는 동일
// 따라서 문자열을 순회하며 각 숫자별 덩어리 수 세주기 - 첫 글자가 무엇인지 보고, 이후 글자들을 순회하며 전 글자와 달라졌을 경우 해당 글자가 무엇인지 보기
// 이렇게 0번 덩어리 수와 1번 덩어리 수를 확인한 후 그 중 작은 덩어리 개수 출력하기