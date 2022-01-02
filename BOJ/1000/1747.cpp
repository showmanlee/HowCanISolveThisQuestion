// 소수&팰린드롬
// https://www.acmicpc.net/problem/1747

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> prime(1003002, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(1003002); i++) {
		if (prime[i]) {
			for (int j = i * 2; j < 1003002; j += i)
				prime[j] = false;
		}
	}
	int n;
	cin >> n;
	int res = 0;
	while (true) {
		if (prime[n]) {
			string s = to_string(n);
			bool suc = true;
			for (int i = 0; i < s.length() / 2; i++) {
				if (s[i] != s[s.length() - i - 1]) {
					suc = false;
					break;
				}
			}
			if (suc) {
				res = n;
				break;
			}
		}
		n++;
	}
	cout << res << '\n';
}

// n보다 크거나 같은 수 중 소수이면서 팰린드롬인 가장 작은 수는?
// 일단 소수 자체는 에라토스테네스로 구하기 - 근데 어디까지?
// n의 최대인 100만인 경우의 답까지 체 사이즈를 지정 - 그리고 그 답은 1003001
// 이후 n을 받고 n을 1씩 올려가며, 소수면서 팰린드롬인 수를 찾으면 그 수를 출력
// 에라토스테네스로 소수를 판정하고, 이를 문자열로 바꿔 팰린드롬을 판정한다