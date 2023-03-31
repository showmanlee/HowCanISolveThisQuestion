// 찬반투표
// https://www.acmicpc.net/problem/27736

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(3);
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		v[p + 1]++;
	}
	if (v[1] >= (n + 1) / 2) {
		cout << "INVALID\n";
	} else {
		cout << (v[2] > v[0] ? "APPROVED" : "REJECTED") << '\n';
	}
}

// 찬반투표에서 기권 표가 전체 표의 절반 이상일 경우 투표가 무효될 떄, 결과 구하기

// 찬성, 기권, 반대가 각각 1, 0, -1로 나오기에 +1하여 배열로 카운트하면 편하다
// 이를 이용해 계산해보자