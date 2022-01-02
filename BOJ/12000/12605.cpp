// 단어순서 뒤집기
// https://www.acmicpc.net/problem/12605

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		string s, t;
		getline(cin, s);
		vector<string> v;
		stringstream ss(s);
		while (ss >> t)
			v.push_back(t);
		reverse(v.begin(), v.end());
		cout << "Case #" << i << ": ";
		for (string p : v)
			cout << p << ' ';
		cout << '\n';
	}
}

// 띄어쓰기가 포함된 문자열의 단어 순서 뒤집어 출력하기

// 문자열을 getline으로 받고, stringstream으로 단어 뽑아서 배열에 넣은 뒤, reverse로 뒤집어주기
// 숫자 받고 문자열 받기 전 cin.ignore()로 플러싱