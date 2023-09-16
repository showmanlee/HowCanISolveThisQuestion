// 실버와 소수는 둘다 S로 시작한다
// https://www.acmicpc.net/problem/29728

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<bool> prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= n; j += i)
				prime[j] = false;
		}
	}
	if (n == 1) {
		cout << "1 0\n";
	} else if (n == 2) {
		cout << "0 2\n";
	} else {
		bool side = false;
		char front = 'S', back = 'S';
		int b = 0, s = 2;
		for (int i = 3; i <= n; i++) {
			if (prime[i]) {
				if (side) {
					if (back == 'B') {
						b--;
						s++;
					}
					back = 'S';
					s++;
				} else {
					if (front == 'B') {
						b--;
						s++;
					}
					front = 'S';
					s++;
				}
				side = !side;
			} else {
				if (side) {
					back = 'B';
				} else {
					front = 'B';
				}
				b++;
			}
		}
		cout << b << ' ' << s << '\n';
	}
}

// 빈 문자열에 i번째 순서가 소수가 아닐 때는 B, 소수일 때는 맨 뒤가 B면 S로 바꾼 뒤 S 추가 후 반전하며 문자를 채울 때, 문자를 n번 추가한 문자열의 B, S 수는?

// 소수야 에라토스테네스로 구할 수 있다고 해도, 직접 문자열을 채우고 반전하기에는 시간이 너무 오래 걸림
// 어차피 맨 뒤나 반전 상태의 맨 뒤인 맨 앞만 보면 되므로 맨 앞과 맨 뒤, 그리고 방향만 기억하며 계산해나간다
// 규칙을 일반화하는데 제약이 있는 길이 1, 2의 경우 별도로 처리