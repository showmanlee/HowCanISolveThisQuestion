// Случай с игрой
// https://www.acmicpc.net/problem/29267

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int res = 0;
	int mem = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "ammo") {
			res += k;
		} else if (s == "save") {
			mem = res;
		} else if (s == "shoot") {
			res--;
		} else if (s == "load") {
			res = mem;
		}
		cout << res << '\n';
	}
}

// 서로 숫자카드 하나씩 내서 더 높은 쪽이 모두 가져가서 점수를 모두 얻는 게임을 할 때, 최종 결과 출력하기