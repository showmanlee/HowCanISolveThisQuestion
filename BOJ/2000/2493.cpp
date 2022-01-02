// 탑
// https://www.acmicpc.net/problem/2493

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(n + 1), res(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> board[i];
	stack<int> st;
	for (int i = 1; i <= n; i++) {
		while (!st.empty()) {
			if (board[st.top()] > board[i]) {
				res[i] = st.top();
				break;
			}
			st.pop();
		}
		if (st.empty())
			res[i] = 0;
		st.push(i);
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
	cout << '\n';
}

// 왼쪽으로 레이저를 쏘는 탑이 일렬로 서 있을 때, 각 탑에서 쏜 레이저을 어떤 탑이 맞는지 출력하기

// n^2 기반으로 한 탑에서 역순으로 돌며 맞는 탑을 찾는 것은 불가능 - 스택을 도입하면 n 기반으로 풀 수 있음
// 모든 탑을 순회하는데, 순회를 시작할 때 스택이 비어있는지 확인
// 만약 비어있지 않다면 스택 위에 있는 탑이 현재 탑보다 높은지 확인, 높다면 해당 탑에 레이저가 맞는 것이고, 그렇지 않다면 스택에서 해당 탑을 pop해 다음 탑을 탐색한다
// 그 결과 스택이 비게 되거나 원래부터 탑이 비어 있었다면 레이저를 맞는 탑이 없다는 의미이므로 0 출력
// 이후 현재 탑을 스택에 넣는다

// 원리는 자신 왼쪽의 탑들을 스택에 넣는 것 - 넣는 순서는 왼쪽 순서대로(역순으로 빠지고)
// 어떤 탑이 들어가기 전에 자신 왼쪽의 탑을 탐색한 후, 나보다 작은 탑이었다면 해당 탑을 스택에서 뺀다
// - 어차피 나보다 작은 탑들은 내 오른쪽의 탑들에게 영향을 주지 못하기 때문 - 나중에 나오는 탑이 작다고 해도 내가 막으니까
// 하지만 내 레이저를 막는 탑은 스택에서 빼지 않는다 - 다른 탑이 그 탑에 영향을 받을 수 있기 때문에