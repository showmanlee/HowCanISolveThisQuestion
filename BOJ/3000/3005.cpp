// 크로스워드 퍼즐 쳐다보기
// https://www.acmicpc.net/problem/3005

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
	string buffer = "";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '#') {
				if (buffer.length() >= 2) {
					v.push_back(buffer);
				}
				buffer = "";
			} else {
				buffer += board[i][j];
			}
		}
		if (buffer.length() >= 2) {
			v.push_back(buffer);
		}
		buffer = "";
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[j][i] == '#') {
				if (buffer.length() >= 2) {
					v.push_back(buffer);
				}
				buffer = "";
			} else {
				buffer += board[j][i];
			}
		}
		if (buffer.length() >= 2) {
			v.push_back(buffer);
		}
		buffer = "";
	}
	sort(v.begin(), v.end());
	cout << v[0] << '\n';
}

// 주어진 크로드워드에 있는 단어 중 사전 순으로 가장 앞에 있는 단어는?

// 크로스워드를 구한 후, 각 열/행을 순회하면서 단어들을 가져온다 - 그리고 정렬한다