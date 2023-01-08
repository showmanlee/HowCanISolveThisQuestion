// Time to Decompress
// https://www.acmicpc.net/problem/17010

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		char c;
		cin >> n >> c;
		for (int i = 0; i < n; i++) {
			cout << c;
		}
		cout << '\n';
	}
}
 
// 주어진 문자를 n번 출력하기

// 기본적인 반복문...