// 인생은 한 방
// https://www.acmicpc.net/problem/25183

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	bool res = false;
	for (int i = 0; i < n - 4; i++) {
		char key = s[i];
		int len = 1;
		for (int j = i + 1; j < n; j++) {
			if (s[j] == key + 1 || s[j] == key - 1) {
				len++;
				key = s[j];
			} else {
				break;
			}
		}
		if (len >= 5) {
			res = true;
			break;
		}
	}
	cout << (res ? "YES" : "NO") << '\n';
}

// 주어진 문자열의 길이 5 이상의 부분 문자열이 사전 순으로 서로 붙은 문자열끼리 구성되어 있는지 판정하기

// ABCDE, EDCBA 뿐만 아니라, ABABA와 같이 순서가 바뀌는 경우도 됨
// 길이가 5 이상이어야 되므로 주어진 문자열의 n-5 인덱스까지 기준을 잡고, 해당 문자부터 앞으로 가면서 조건을 만족하는지 찾기
// 만약 이어지는 길이가 5 이상이면 성공