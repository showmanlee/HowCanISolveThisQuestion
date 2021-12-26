// 문자열 집합
// https://www.acmicpc.net/problem/14425

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct trie {
	trie* next[27];
	trie() {
		for (int i = 0; i < 27; i++)
			next[i] = NULL;
	}
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	trie* next[26];
	for (int i = 0; i < 26; i++) {
		next[i] = NULL;
	}
	int n, m;
	cin >> n >> m;
	for (int t = 0; t < n; t++) {
		string s;
		cin >> s;
		if (!next[s[0] - 'a']) {
			next[s[0] - 'a'] = new trie();
		}
		trie* ptr = next[s[0] - 'a'];
		for (int i = 1; i < s.length(); i++) {
			if (!ptr->next[s[i] - 'a']) {
				ptr->next[s[i] - 'a'] = new trie();
			}
			ptr = ptr->next[s[i] - 'a'];
		}
		ptr->next[26] = new trie();
	}
	int res = 0;
	for (int t = 0; t < m; t++) {
		string s;
		cin >> s;
		bool ret = true;
		trie* ptr = next[s[0] - 'a'];
		for (int i = 1; i < s.length(); i++) {
			if (!ptr) {
				ret = false;
				break;
			}
			ptr = ptr->next[s[i] - 'a'];
		}
		if (!ptr || !ptr->next[26]) {
			ret = false;
		}
		res += (ret ? 1 : 0);
	}
	cout << res << '\n';
}

// m개의 문자열 중 n개의 문자열 집합에 있는 문자열 개수 구하기

// n과 m이 모두 10000까지 주어질 수 있기에, n^2 탐색은 불가능함
// 효율성을 늘리기 위해 저번에 숫자 문자열에 썼던 트라이를 활용해볼 수 있다 - 각 문자 다음에 어떤 글자가 들어갈 수 있는지 나타내는 포인터 트리
// 다만 '집합에 들어간 문자열'은 부분 문자열이 아니기에 문자열 끝 부분을 별도로 표시해줘야 함
// 언뜻 보면 비효율적으로 보일 수 있으나 사실은 상당히 효율적인 방법