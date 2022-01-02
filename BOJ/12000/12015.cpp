// 가장 긴 증가하는 부분 수열 2
// https://www.acmicpc.net/problem/12015

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
	vector<int> dp(1);
	for (int i = 0; i < n; i++) {
		if (dp.back() < board[i])
			dp.push_back(board[i]);
		else 
			*lower_bound(dp.begin(), dp.end(), board[i]) = board[i];
	}
	cout << (dp.size() - 1) << '\n';
}

// 주어진 수열에서 일부 수를 뽑아서 만들 수 있는 가장 긴 증가하는 부분 수열 구하기

// LIS 문제 - 이제 n이 100만이라서 nlogn 방식을 사용해야 함
// 여기서 dp는 가변 배열이 되어, 인덱스 길이의 LIS 안에서 만날 수 있는 가장 작은 수를 기록하게 됨 - dp[0] = 0
// 일단 보드를 받은 뒤, 보드를 순회하며 dp의 마지막칸의 수가 현재 수보다 작은지 확인
// 만약 그렇다면 더 긴 LIS를 만들 수 있다는 의미이므로 dp뒤에 해당 수 삽입
// 그렇지 않다면 dp안에서 현재 수보다 같거나 없다면 그보다 큰 수 중 작은 수를 찾아 해당 위치의 수를 현재 수로 갱신하기 - lower_bound
// dp는 정렬되어 있음이 보장되므로 이분 탐색을 돌릴 수 있음 - 내장 함수인 lower_bound로 반환되는 포인터를 이용해 갱신 처리
// dp를 갱신한 뒤에는 이전의 수를 버리기 - 이전의 수는 현재 수 앞에 있으므로 더 이상 LIS 형성에 도움을 주지 못함
// 결과적으로 dp의 길이 - 1이 답이 됨