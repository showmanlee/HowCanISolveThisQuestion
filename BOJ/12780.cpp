// 원피스
// https://www.acmicpc.net/problem/12780

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string h, n;
	cin >> h >> n;
	int res = 0;
	for (int i = 0; i < h.length() - n.length() + 1; i++)
		if (h.substr(i, n.length()) == n)
			res++;
	cout << res << '\n';
}

// 긴 문자열에서 특정 문자열이 몇 번 나오는가?
// for에서 substr 돌리기 - h.length() == n.length() 일 경우에 주의