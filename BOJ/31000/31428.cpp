// 엘리스 트랙 매칭
// https://www.acmicpc.net/problem/31428

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<char> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	char c;
	cin >> c;
	int res = 0;
	for (char h : v) {
		if (c == h) {
			res++;
		}
	}
	cout << res << '\n';
}

// n일 중 m일을 보냈을 때, 진행도를 24시간으로 표시한 결과 출력하기