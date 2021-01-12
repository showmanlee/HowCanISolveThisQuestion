// 로또
// https://www.acmicpc.net/problem/6603

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& nums, vector<int> ans, int n, int s, int d) {
	if (d == 6) {
		for (int i : ans)
			cout << i << ' ';
		cout << '\n';
		return;
	}
	for (int i = s; i < n; i++) {
		ans[d] = nums[i];
		dfs(nums, ans, n, i + 1, d + 1);
	}
}

int main(void) {
	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			break;
		vector<int> nums(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		dfs(nums, vector<int>(6), n, 0, 0);
		cout << '\n';
	}
}

// 독일 로또(6/49)에서 특정 숫자 조합에서 선택할 수 있는 모든 경우의 수 출력하기
// 개수는 조합으로 구하면 되고, 경우의 수는 DFS로 구하면 된다는 것을 기억할 것
// 시작 지점과 깊이를 저장해, 깊이가 목표라면 결과를 저장한 배열의 값들을 출력, 그렇지 않으면 시작 지점 뒤에 있는 숫자를 결과 배열에 넣어 다시 dfs 돌리기
// 재귀를 활용한 조합 생성 - 응용하면 순열 생성도 가능할까?s