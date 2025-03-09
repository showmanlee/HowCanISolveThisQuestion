// 곱셈을 누가 이렇게 해 ㅋㅋ
// https://www.acmicpc.net/problem/33557

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int t = 0; t < n; t++) {
		string a, b;
		cin >> a >> b;
		string resi = to_string(stoll(a) * stoll(b));
		string ress;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for (int i = 0; i < max(a.length(), b.length()); i++) {
			if (i >= a.length()) {
				ress = b[i] + ress;
			} else if (i >= b.length()) {
				ress = a[i] + ress;
			} else {
				string p = to_string((a[i] - '0') * (b[i] - '0'));
				ress = p + ress;
			}
		}
		cout << (resi == ress) << '\n';
	}
}

// 정수끼리의 곱셈에서 일반적인 곱셈과 각 자릿수끼리 곱한 결과를 이어붙인 결과가 동일한지 출력하기