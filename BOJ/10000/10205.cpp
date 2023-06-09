// 헤라클레스와 히드라
// https://www.acmicpc.net/problem/10205

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		for (char c : s) {
			if (c == 'b') {
				n--;
			} else if (c == 'c') {
				n++;
			}
		}
		cout << "Data Set " << t << ":\n" << n << '\n';
		if (t != tt) {
			cout << '\n';
		}
	}
}

// n개의 머리를 각진 히드라에게 헤라클레스가 머리를 그냥 자르거나 머리를 자르고 불로 지져 새 머리가 나오지 못하도록 할 때, 최종적으로 남은 히드라의 머리 구하기

// 전체 문자열에서 c가 나오면 +1(-1+2), b가 나오면 -1하여 결과를 구한다