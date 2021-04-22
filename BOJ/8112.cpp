// 0과 1 - 2
// https://www.acmicpc.net/problem/8112

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, char> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		vector<bool> visit(n);
		vector<pr> where(n);
		queue<int> q;
		q.push(1);
		visit[1] = true;
		where[1] = { -1, '1' };
		bool pass = false;
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			if (p == 0) {
				pass = true;
				break;
			}
			int pp = (p * 10) % n;
			if (!visit[pp]) {
				visit[pp] = true;
				where[pp] = { p, '0' };
				q.push(pp);
			}
			pp = (pp + 1) % n;
			if (!visit[pp]) {
				visit[pp] = true;
				where[pp] = { p, '1' };
				q.push(pp);
			}
		}
		if (!pass) {
			cout << "BRAK\n";
			continue;
		}
		string res;
		int i = 0;
		while (i != -1) {
			res = where[i].second + res;
			i = where[i].first;
		}
		cout << res << '\n';
	}
}

// n의 배수 중 0과 1로만 이루어진 가장 작은 자연수 출력하기
// 1에서 길이 제한이 없어지고 n의 최대가 100만이 된 버전
// 따라서 길이로 보던 BRAK 조건을 bfs 탈출 여부로 바꾸기만 하면 됨