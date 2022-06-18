// 서로 다른 부분 문자열의 개수
// https://www.acmicpc.net/problem/11478

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

double PI = 3.14159265359;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	map<string, int> m;
	for (int i = 1; i <= s.length(); i++) {
		for (int j = 0; j < s.length() - i + 1; j++) {
			m[s.substr(j, i)]++;
		}
	}
	cout << m.size() << '\n';
}

// 주어진 문자열에서 얻을 수 있는 부분 문자열의 종류 수 구하기

// 다행히 1000자까지만 주어지므로 n^2로 모든 부분문자열을 구할 수 있음
// 이러면서 map을 통해 중복되지 않게 추린 후, 그 개수를 세면 된다 - 아니면 직접 트리를 만들어도 되고