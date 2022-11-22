// The Walking Adam
// https://www.acmicpc.net/problem/18698

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int res = 0;
		for (char c : s) {
			if (c == 'U') {
				res++;
			} else {
				break;
			}
		}
		cout << res << '\n';
	}
}

// U와 D로 구성된 문자열이 주어질 때, 처음부터 연속되는 U의 길이 구하기

// 문자열을 받은 뒤, 앞에서부터 U가 연속해서 몇 번 나오는지 확인해본다