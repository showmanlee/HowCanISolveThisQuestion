// 딱지놀이
// https://www.acmicpc.net/problem/14696

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, m;
		cin >> n;
		vector<int> a(5), b(5);
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			a[p]++;
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			int p;
			cin >> p;
			b[p]++;
		}
		bool done = false;
		for (int i = 4; i >= 1; i--) {
			if (a[i] != b[i]) {
				cout << (a[i] > b[i] ? "A\n" : "B\n");
				done = true;
				break;
			}
		}
		if (!done) {
			cout << "D\n";
		}
	}
}

// 4/3/2/1의 개수에 따라 승패가 갈리는 게임에서 카드에 적힌 숫자의 종류가 주어질 때, 승자 구하기

// 들어오는 숫자의 수를 센 뒤, 높은 수부터 차례대로 비교를 해준다 - 다르면 높은 쪽 승리, 같으면 다음 수로
// 모든 수가 같으면 무승부 처리