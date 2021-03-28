// Strfry
// https://www.acmicpc.net/problem/11328

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		vector<int> chars(26);
		for (char c : a)
			chars[c - 'a']++;
		for (char c : b)
			chars[c - 'a']--;
		bool fail = false;
		for (int j : chars) {
			if (j != 0) {
				fail = true;
				break;
			}
		}
		cout << (fail ? "Impossible" : "Possible") << '\n';
	}
}

// 주어진 문자열을 랜덤으로 재배열해 새 문자열을 만드는 strfry로 두 문자열이 나올 수 있는지 판단하기
// 알파벳 소문자만 나오기 때문에 등장하는 글자 수를 세서 두 문자열에 등장하는 문자 종류가 모두 같으면 가능 판정
// 첫 문자열 순회 시에는 더하기, 마지막 문자열 순회 시에는 빼기를 해서 카운팅 배열을 하나로 줄일 수 있음 