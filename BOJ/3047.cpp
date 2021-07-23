// ABC
// https://www.acmicpc.net/problem/3047

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(3);
	for (int i = 0; i < 3; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < 3; i++) {
		char c;
		cin >> c;
		cout << v[c - 'A'] << ' ';
	}
	cout << '\n';
}

// A < B < C를 만족하는 변수 A, B, C가 될 수 있는 세 수와 A, B, C의 배치 순서가 주어질 때, 이대로 출력하기

// 세 수를 정렬해 A B C를 할당한 다음, 주어지는 문자들을 이용해 수 출력하기