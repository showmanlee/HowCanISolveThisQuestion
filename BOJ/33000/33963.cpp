// 돈복사
// https://www.acmicpc.net/problem/33963

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	long long p = n;
	int res = 0;
	while (true) {
		p *= 2;
		if (to_string(p).length() > to_string(n).length()) {
			break;
		}
		res++;
	}
	cout << res << '\n';
}

// 주어진 자연수를 2배씩 곱해서 자릿수 길이가 바뀌는 횟수 구하기