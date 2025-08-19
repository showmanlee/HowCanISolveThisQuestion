// Word Mix
// https://www.acmicpc.net/problem/26590

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	int n = min(a.length(), b.length());
	string res;
	for (int i = 0; i < n; i++) {
		res += (i % 2 == 0 ? a[i] : b[i]);
	}
	cout << res << '\n';
}

// 주어진 2가지 문자열에서 교대로 한 글자씩 가져와 출력하기