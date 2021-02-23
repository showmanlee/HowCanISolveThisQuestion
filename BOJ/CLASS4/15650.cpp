// N과 M (2)
// https://www.acmicpc.net/problem/15650

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;

void nm(vector<int> v, int k) {
	if (k == m) {
		for (int i : v)
			cout << i << ' ';
		cout << '\n';
	}
	else {
		for (int i = v[k - 1] + 1; i <= n; i++) {
			v[k] = i;
			nm(v, k + 1);
		}
	}
}

int main(void) {
	cin >> n >> m;
	vector<int> v(m);
	for (int i = 1; i <= n; i++) {
		v[0] = i;
		nm(v, 1);
	}
}

// N까지의 자연수 중 중복 없이 M개를 고른 수열 출력하기
// 범위가 8까지니까 재귀로 처리 가능
// vector는 참조니까 push_back으로 넣지 말고 인덱스로 넣기 - 아니면 vector를 전역 변수로 만들던가