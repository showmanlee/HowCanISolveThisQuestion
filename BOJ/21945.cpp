// Palindromes
// https://www.acmicpc.net/problem/21945

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	long long res = 0;
	for (int t = 0; t < n; t++) {
		string s;
		cin >> s;
		bool good = true;
		for (int i = 0; i < s.length() / 2; i++)
			if (s[i] != s[s.length() - 1 - i])
				good = false;
		if (good)
			res += stoi(s);
	}
	cout << res << '\n';
}

// 주어진 자연수 중 팰린드롬을 이루는 자연수의 합 구하기

// 자연수를 문자열로 받아 팰린드롬 여부 확인, 이후 맞으면 정수로 변환하여 결과값에 더하기