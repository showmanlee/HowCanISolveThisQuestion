// Game Night
// https://www.acmicpc.net/problem/33253

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
	string a, b;
	cin >> a >> b;
	vector<int> ca(26), cb(26);
	for (char c : a) {
		ca[c - 'a']++;
	}
	for (char c : b) {
		cb[c - 'a']++;
	}
	int res = 0;
	for (int i = 0; i < 26; i++) {
		res += abs(ca[i] - cb[i]);
	}
	res /= 2;
	cout << res << '\n';
}

// 주어진 문자열의 문자 순서를 바꿔 다른 문자열을 만들 때, 교체가 필요한 문자 개수 구하기