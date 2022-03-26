// 팬그램
// https://www.acmicpc.net/problem/10384

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string n;
	getline(cin, n);
	int nn = stoi(n);
	for (int i = 1; i <= nn; i++) {
		string s;
		getline(cin, s);
		vector<int> cnt(26);
		for (char c : s) {
			if (isupper(c)) {
				cnt[c - 'A']++;
			}
			else if (islower(c)) {
				cnt[c - 'a']++;
			}
		}
		int res = 987654321;
		for (int j = 0; j < 26; j++) {
			res = min(res, cnt[j]);
		}
		cout << "Case " << i << ": ";
		if (res == 0) {
			cout << "Not a pangram";
		}
		else if (res == 1) {
			cout << "Pangram!";
		}
		else if (res == 2) {
			cout << "Double pangram!!";
		}
		else {
			cout << "Triple pangram!!!";
		}
		cout << '\n';
	}
}

// 문자열이 주어질 때, 글자가 몇 번씩 사용된(3번가지) 팬그램인지 출력하기

// 문자열을 getline으로 받고, 문자들을 돌며 해당 문자가 대문자나 소문자인 경우 얼만큼 사용되었는지 배열에 기록하기
// 이후 배열을 순회하며 나온 최솟값이 팬그램 글자 수