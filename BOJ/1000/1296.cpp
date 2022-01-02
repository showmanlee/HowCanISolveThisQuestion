// 데이트
// https://www.acmicpc.net/problem/1296

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	string oh;
	cin >> oh;
	int ol = 0, oo = 0, ov = 0, oe = 0;
	for (char c : oh) {
		if (c == 'L')
			ol++;
		else if (c == 'O')
			oo++;
		else if (c == 'V')
			ov++;
		else if (c == 'E')
			oe++;
	}
	int n;
	cin >> n;
	vector<string> girls(n);
	for (int i = 0; i < n; i++)
		cin >> girls[i];
	sort(girls.begin(), girls.end());
	int max = 0, maxi = 0;
	for (int i = 0; i < n; i++) {
		int l = ol, o = oo, v = ov, e = oe;
		for (char c : girls[i]) {
			if (c == 'L')
				l++;
			else if (c == 'O')
				o++;
			else if (c == 'V')
				v++;
			else if (c == 'E')
				e++;
		}
		int res = ((l + o) * (l + v) * (l + e) * (o + v) * (o + e) * (v + e)) % 100;
		if (res > max) {
			max = res;
			maxi = i;
		}
	}
	cout << girls[maxi] << '\n';
}

// 이름에 나오는 LOVE 글자 수를 세서 확률 만들어서 가장 확률이 높은 사람 찾기
// 구현 구현 구현