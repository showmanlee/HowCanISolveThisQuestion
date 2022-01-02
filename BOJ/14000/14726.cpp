// 신용카드 판별
// https://www.acmicpc.net/problem/14726

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int t = 0; t < n; t++) {
		string s;
		cin >> s;
		int sum = 0;
		for (int i = 0; i < 16; i++) {
			int p = (s[i] - '0') * (i % 2 == 0 ? 2 : 1);
			if (p >= 10)
				p = p / 10 + p % 10;
			sum += p;
		}
		cout << (sum % 10 == 0 ? "T" : "F") << '\n';
	}
}

// 주어진 신용카드 번호가 정당한지 판별하기

// 맨 오른쪽부터 홀수번은 그냥, 짝수번은 2를 곱해서(그게 10 이상이면 각 자리수 더하기) 더한 합이 10으로 나누어떨어지면 T, 아니면 F
// 홀짝 구분이 오른쪽부터 들어감에 주의 - 왼쪽부터 가면 홀수번째가 2가 됨