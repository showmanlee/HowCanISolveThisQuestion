// 대충 더해
// https://www.acmicpc.net/problem/8949

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	int idxa = a.length() - 1, idxb = b.length() - 1;
	string res;
	while (idxa >= 0 || idxb >= 0) {
		int aa = 0, bb = 0;
		if (idxa >= 0) {
			aa = a[idxa] - '0';
		}
		if (idxb >= 0) {
			bb = b[idxb] - '0';
		}
		int pp = aa + bb;
		res = to_string(pp) + res;
		idxa--;
		idxb--;
	}
	cout << res << '\n';
}

// 두 수의 덧셈에서 받아올림을 하지 않고 한 자리에 두 자리 이상의 수를 쓸 수 있을 때, 결과 출력하기

// 실제 덧셈을 하듯이 맨 뒷자리에서부터 더해가면서, 덧셈 결과를 앞으로 계속 붙여나간다