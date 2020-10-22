// 듣보잡
// https://www.acmicpc.net/problem/1764

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<string> d(n);
	vector<string> b(m);
	vector<string> db;
	for (int i = 0; i < n; i++)
		cin >> d[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort(d.begin(), d.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < b.size(); i++)
		if (binary_search(d.begin(), d.end(), b[i]))
			db.push_back(b[i]);

	cout << db.size() << '\n';
	for (int i = 0; i < db.size(); i++)
		cout << db[i] << '\n';
}

// 두 리스트에서 동시에 나온 문자열 찾기
// binary_search(begin, end, x) -> 해당 리스트에서 값 존재 여부를 이진 탐색으로 검색, t/f 반환하는 함수
// 더 이상 원소를 찾는데 n^2를 사용할 필요가 없어졌음