// 애너그램
// https://www.acmicpc.net/problem/6996

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		bool res = false;
		if (a.length() == b.length()) {
			vector<int> aa(26), bb(26);
			for (int j = 0; j < a.length(); j++) {
				aa[a[j] - 'a']++;
				bb[b[j] - 'a']++;
			}
			res = true;
			for (int j = 0; j < 26; j++) {
				if (aa[j] != bb[j]) {
					res = false;
					break;
				}
			}
		}
		cout << a << " & " << b << " are " << (res ? "" : "NOT ") << "anagrams.\n";
	}
}

// 주어진 두 문자열이 애너그램 관계인지 판정하기

// 애너그램은 어떤 문자열의 문자 순서를 바꾸어 다른 문자열로 만들 수 있는 경우
// 따라서 기본적으로 두 문자열의 길이가 같아야 하고, 등장하는 알파벳의 종류와 개수가 모두 동일해야 한다