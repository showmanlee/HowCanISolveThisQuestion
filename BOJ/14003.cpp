// 가장 긴 증가하는 부분 수열 5
// https://www.acmicpc.net/problem/14003

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(n);
	for (int i = 0; i < n; i++)
		cin >> board[i];
	vector<int> dp(1), dp_pos(1), prev(n, -1);
	dp[0] = -1000000001;
	dp_pos[0] = -1;
	for (int i = 0; i < n; i++) {
		if (dp.back() < board[i]) {
			prev[i] = dp_pos.back();
			dp.push_back(board[i]);
			dp_pos.push_back(i);
		}
		else {
			int idx = lower_bound(dp.begin(), dp.end(), board[i]) - dp.begin();
			dp[idx] = board[i];
			dp_pos[idx] = i;
			prev[i] = dp_pos[idx - 1];
		}
	}
	cout << (dp.size() - 1) << '\n';
	vector<int> res;
	int cur = dp_pos.back();
	while (cur != -1) {
		res.push_back(board[cur]);
		cur = prev[cur];
	}
	reverse(res.begin(), res.end());
	for (int i : res)
		cout << i << ' ';
	cout << '\n';
}

// 주어진 수열에서 일부 수를 뽑아서 만들 수 있는 가장 긴 증가하는 부분 수열을 구하고 출력하기

// nlogn 기반 LIS에서 LIS 상의 이전 위치를 뽑아내기 위해 prev와 dp_pos(dp에서의 원소 위치) 활용하기
// prev는 dp_pos를 활용해 LIS 상의 이전 위치를 저장하는 배열 - dp_pos는 dp로 들어온 수가 어디에서 왔는지 저장하는 배열
// dp에 새로운 수가 삽입되거나 갱신되는 경우 dp_pos의 같은 위치에 해당 수의 인덱스가 삽입/갱신
// 동시에 해당 수 위치의 prev에 dp_pos[idx - 1]를 저장 - 나중에 dp가 갱신되더라도 해당 수와 연결된 이전 수는 갱신되지 않음
// 이렇게 갱신을 마친 후 dp_pos 상의 마지막 인덱스에서 prev를 타고 올라가면 LIS가 됨 - 이를 저장한 후 반전하여 출력하기

// solved.ac 플3 달성! - 이젠 플래티넘 상위 문제들을 주로 풀어야 레벨업을 할 수 있다