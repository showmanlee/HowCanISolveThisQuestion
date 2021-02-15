// 암호
// https://www.acmicpc.net/problem/1855

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k;
	string s;
	cin >> k >> s;
	vector<vector<char>> v(s.length() / k, vector<char>(k));
	for (int i = 0; i < s.length() / k; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < k; j++)
				v[i][j] = s[i * k + j];
		}
		else {
			for (int j = k - 1; j >= 0; j--)
				v[i][j] = s[i * k + (k - j - 1)];
		}
	}
	for (int j = 0; j < k; j++)
		for (int i = 0; i < s.length() / k; i++)
			cout << v[i][j];
}

// 행-열 순서대로 채운 문자열을 지그재그로 나열한 암호를 해독해보자
// 가장 간단한 건 배열을 직접 만들어 채우는 것