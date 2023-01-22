// 크로스워드
// https://www.acmicpc.net/problem/1706

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string p;
		for (int j = 0; j < m; j++) {
			if (board[i][j] != '#') {
				p += board[i][j];
			} else {
				if (p.length() > 1) {
					v.push_back(p);
				}
				p = "";
			}
		}
		if (p.length() > 1) {
			v.push_back(p);
		}
	}
	for (int i = 0; i < m; i++) {
		string p;
		for (int j = 0; j < n; j++) {
			if (board[j][i] != '#') {
				p += board[j][i];
			} else {
				if (p.length() > 1) {
					v.push_back(p);
				}
				p = "";
			}
		}
		if (p.length() > 1) {
			v.push_back(p);
		}
	}
	sort(v.begin(), v.end());
	cout << v[0] << '\n';
}

// n*m 크기의 완성된 크로스워드 퍼즐이 주어질 때, 사전 순으로 가장 앞선 단어는?

// 보드의 각 줄에 대해 2글자 이상의 단어를 뽑은 뒤, 정렬하여 출력한다
// 각 줄에 대해 #이나 끝이 나왔을 때 현재까지 쌓인 글자 수가 2글자 이상이면 배열에 넣기, 그리고 길이에 관계없이 초기화.