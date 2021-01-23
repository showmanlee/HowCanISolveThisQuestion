// 수업시간에 교수님 몰래 교실을 나간 상근이
// https://www.acmicpc.net/problem/2825

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<long long> count(1024);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int p = 0;
		for (char c : s)
			p |= 1 << (c - '0');
		count[p]++;
	}

	long long res = 0;
	for (int i = 0; i < 1024; i++) {
		for (int j = i + 1; j < 1024; j++) {
			if ((i & j) != 0)
				res += count[i] * count[j];
		}
		res += count[i] * (count[i] - 1) / 2;
	}
	cout << res << '\n';
}

// 주어진 자연수들 중 '친구'(두 수를 이루는 숫자가 하나 이상 겹치는 쌍)의 개수 찾기
// 숫자 등장 여부를 비트마스킹으로 표현한 후, 표현된 결과들을 바탕으로 친구 수를 계산할 수 있다
// 같은 숫자 사이에는 nC2(n * (n - 1) / 2)개의 친구가 있고, 다른 숫자 사이에는 a[i] * a[j]개의 친구가 있다
// 단 다른 숫자가 i & j != 0(겹치는 숫자가 있는 경우)을 만족하는 경우에만 계산할 것
// 결과는 long long으로 출력해야 함