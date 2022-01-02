// 거꾸로 구구단
// https://www.acmicpc.net/problem/13410

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	int res = 0;
	for (int i = 1; i <= k; i++) {
		string s = to_string(n * i);
		string p = "";
		for (char c : s)
			p = c + p;
		if (res < stoi(p))
			res = stoi(p);
	}
	cout << res << '\n';
}

// 일반적인 k단의 수를 거꾸로 저장하는 거꾸로 k단에서 n단의 최댓값은?
// string을 이용해 숫자를 거꾸로 붙이고, 이를 이용해 결과 갱신하기