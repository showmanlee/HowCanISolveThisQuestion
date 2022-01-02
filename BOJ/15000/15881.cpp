// Pen Pineapple Apple Pen
// https://www.acmicpc.net/problem/15881

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
	int res = 0;
	for (int i = 0; i < n - 3; i++) {
		if (s[i] == 'p' && s[i + 1] == 'P' && s[i + 2] == 'A' && s[i + 3] == 'p') {
			res++;
			i += 3;
		}
	}
	cout << res << '\n';
}

// 주어진 문자열에서 겹치지 않고 나올 수 있는 pPAp 개수 구하기

// 문자열의 각 문자들을 순회하면서 pPAp가 나오면 인덱스를 +3하기 - +4하지 않는 이유는 for에서 ++하기 때문
// pPAp에 대소문자 구분이 적용됨에 주의 - p는 펜, P는 파인애플