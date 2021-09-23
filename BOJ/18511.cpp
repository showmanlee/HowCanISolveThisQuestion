// 큰 수 구성하기
// https://www.acmicpc.net/problem/18511

#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int nums[3];
int res;

void dfs(int p) {
	p *= 10;
	for (int i = 0; i < k; i++) {
		int pp = p + nums[i];
		if (pp <= n) {
			res = max(pp, res);
			dfs(pp);
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> nums[i];
	res = 0;
	dfs(0);
	cout << res << '\n';
}

// n 이하의 자연수 중 주어진 숫자로만 구성된 가장 큰 수는?

// 주어지는 숫자는 3개 이하, 중복 사용 가능
// n이 최대 1억까지 주어지므로 최대 3^8로 브포로 접근 가능
// 브포로 뒤에서부터 한 자리씩 채워가며 만드는데, 만약 만든 수가 n 이하인 경우 결과값에 갱신시킨 후 다음 자리로 넘어가기
// 그렇게 탐색하다보면 조건에 맞는 값이 나오게 됩니다