// Knights Move
// https://www.acmicpc.net/problem/34381

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int x = s[0] - 'a';
	int y = s[1] - '1';
	vector<string> res;
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= 8 || yy >= 8) {
			continue;
		}
		string s;
		s += (char)(xx + 'a');
		s += (char)(yy + '1');
		res.push_back(s);
	}
	sort(res.begin(), res.end());
	for (string s : res) {
		cout << s << '\n';
	}
}

// 나이트의 위치가 주어질 때 이동할 수 있는 지점 출력하기