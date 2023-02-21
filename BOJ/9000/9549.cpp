// 암호화된 비밀번호
// https://www.acmicpc.net/problem/9549

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string a, b;
		cin >> a >> b;
		vector<int> key(26), cur(26);
		for (char c : b) {
			key[c - 'a']++;
		}
		for (int i = 0; i < b.length(); i++) {
			cur[a[i] - 'a']++;
		}
		bool res = false;
		for (int i = 0; i <= a.length() - b.length(); i++) {
			res = true;
			for (int j = 0; j < 26; j++) {
				if (key[j] != cur[j]) {
					res = false;
					break;
				}
			} 
			if (res) {
				break;
			}
			cur[a[i] - 'a']--;
			if (i + b.length() < a.length()) {
				cur[a[i + b.length()] - 'a']++;
			}
		}
		cout << (res ? "YES" : "NO") << '\n';
	}
}

// 소문자로 구성된 평문의 글자 순서를 섞은 뒤 앞뒤에 글자를 넣는 방식으로 암호화를 할 때, 주어진 암호문이 주어진 평문을 암호화한 형태인지 확인하기

// 평문 길이만큼 연속된 암호문의 부분 문자열에 평문과 같은 문자들로 구성되어 있는지 확인하기