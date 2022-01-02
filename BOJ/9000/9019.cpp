// DSLR
// https://www.acmicpc.net/problem/9019

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, string> pr;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		queue<pr> q;
		vector<bool> visit(10000);
		cin >> a >> b;
		q.push({ a, "" });
		visit[a] = true;
		while (!q.empty()) {
			pr p = q.front();
			if (p.first == b)
				break;
			q.pop();
			if (!visit[p.first * 2 % 10000]) {
				q.push({ p.first * 2 % 10000, p.second + "D" });
				visit[p.first * 2 % 10000] = true;
			}
			if (!visit[p.first == 0 ? 9999 : p.first - 1]) {
				q.push({ (p.first == 0 ? 9999 : p.first - 1), p.second + "S" });
				visit[(p.first == 0 ? 9999 : p.first - 1)] = true;
			}
			if (!visit[(p.first % 1000 * 10) + (p.first / 1000)]) {
				q.push({ (p.first % 1000 * 10) + (p.first / 1000), p.second + "L" });
				visit[(p.first % 1000 * 10) + (p.first / 1000)] = true;
			}
			if (!visit[(p.first / 10) + (p.first % 10 * 1000)]) {
				q.push({ (p.first / 10) + (p.first % 10 * 1000), p.second + "R" });
				visit[(p.first / 10) + (p.first % 10 * 1000)] = true;
			}
		}
		cout << q.front().second << '\n';
	}
}

// D - n * 2 % 10000
// S - n - 1 (if n == 0 then n = 9999)
// L - (n % 1000 * 10) + (n / 1000)(자릿수 왼쪽으로 회전)
// R - (n / 10) + (n % 10 * 1000)(자릿수 오른쪽으로 회전)
// 단순히 숫자를 바꾸는 것 같지만 이런 문제를 BFS로 풀 줄 알아야 함
// 다행히 이 문제는 경우의 수가 여러 개라면 아무 거나 출력해도 됨
// + make_pair 대신 {}로 넣어도 되더라