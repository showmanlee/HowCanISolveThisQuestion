// 터치스크린 키보드
// https://www.acmicpc.net/problem/3961

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, string> prs;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<string> key = {
		"qwertyuiop",
		"asdfghjkl",
		"zxcvbnm"
	};
	vector<pr> board(26);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			if (key[i][j] != ' ') {
				board[key[i][j] - 'a'] = {i, j};
			}
		}
	}

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string str;
		int n;
		cin >> str >> n;
		vector<string> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		vector<prs> res;
		for (int i = 0; i < n; i++) {
			int dist = 0;
			for (int j = 0; j < str.length(); j++) {
				pr a = board[str[j] - 'a'];
				pr b = board[s[i][j] - 'a'];
				dist += abs(a.first - b.first) + abs(a.second - b.second);
			}
			res.push_back({dist, s[i]});
		}
		sort(res.begin(), res.end());
		for (prs p : res) {
			cout << p.second << ' ' << p.first << '\n';
		}
	} 
}

// 아래와 같이 나열된 키보드에서 한 단어와 문자별 키보드 거리를 잴 여러 단어들이 주어질 때, 거리의 합이 짧은 순서 -> 사전 순서로 출력하기
// qwertyuiop
// asdfghjkl
// zxcvbnm

// 우선 저 보드에 따라 각 문자 위치를 저장해둔다 - char로 꺼내쓸 수 있도록
// 이렇게만 하면 거리 구하는 건 반복문 + abs로 할 수 있고
// 이걸 pair를 이용해 정렬해서 출력하기 - 거리->문자열 순으로