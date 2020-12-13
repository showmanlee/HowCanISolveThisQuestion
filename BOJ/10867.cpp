// 중복 빼고 정렬하기
// https://www.acmicpc.net/problem/10867

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i : v)
		cout << i << ' ';
	cout << '\n';
}

// 주어진 배열에서 중복된 숫자를 빼고 정렬
// C++에서는 sort -> erase(unique)를 사용하면 됨
// 그거 없는 언어에서는 sort 후 중복 숫자 판별해서 출력해도 되고