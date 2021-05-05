// 반지
// https://www.acmicpc.net/problem/5555

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		string p;
		cin >> p;
		p += p;
		for (int j = 0; j < 10; j++) {
			if (p.substr(j, s.length()) == s) {
				res++;
				break;
			}
		}
	}
	cout << res << '\n';
}

// 10개의 알파벳이 적혀있는 n개의 반지 중 특정 문자열이 포함된 반지는 몇 개인가?

// 반지는 끝과 끝이 이어져있음 - AXXXXXXXXA 인 경우에도 AA가 포함되어 있는 것
// 따서 반지 문자열을 2배로 늘려서 나머지 연산 없이 편리하게 부분 문자열을 추출할 수 있도록 설정
// 또한 문자열이 있는 반지의 '개수'를 찾는 거지, 문자열이 나온 '횟수'를 찾는 것이 아님에 주의 - 반지에서 문자열이 나오면 바로 탐색 중단