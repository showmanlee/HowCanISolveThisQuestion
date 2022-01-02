// 히스토그램
// https://www.acmicpc.net/problem/13752

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
		cin >> n;
		for (int i = 0; i < n; i++)
			cout << '=';
		cout << '\n';
	}
}

// 주어진 숫자들에 맞춰 세로 히스토그램 그리기

// 말 그대로 입력한 수만큼 =을 반복해서 그려주면 됨...