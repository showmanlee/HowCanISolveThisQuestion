// 수 묶기
// https://www.acmicpc.net/problem/1744

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int l = 0, r = n - 1;
	long long res = 0;
	while (l < r) {
		if (v[l] < 1 && v[l + 1] < 1) {
			res += v[l] * v[l + 1];
			l += 2;
		}
		else
			break;
	}
	while (r > 0) {
		if (v[r] > 1 && v[r - 1] > 1) {
			res += v[r] * v[r - 1];
			r -= 2;
		}
		else
			break;
	}
	for (int i = l; i <= r; i++)
		res += v[i];
	cout << res << '\n';
}

// 길이가 n인 수열의 수들을 모두 더하는 과정에서 임의의 수 2개를 한 번씩만 묶어 그 수의 곱을 대신 더할 수 있을 때, 얻을 수 있는 최댓값은?

// 기본적으로 정렬한 후, 높은 순서대로 맞붙은 수끼리 서로 곱하면 됨
// 그런데 묶은 수 중에서 1 이하의 수가 있는 경우에는 이 법칙이 통하지 않음
// 만약 어떤 수와 1을 곱하게 되면 어떤 수에 1을 더한 것보다 작은 값이 됨
// 만약 음수와 양수를 곱하게 되면 그 수는 음수가 되어 의미가 없어짐 - 다만 음수와 음수를 곱하면 양수가 되어 유리해짐(-1을 곱해도)
// 만약 어떤 수에 0을 곱하게 되면 양수의 경우 의미가 없어지나, 음수의 경우 더 유리해짐(음수에서 0이 됨)
// 이 조건들을 봤을 때, 1을 기준으로 왼쪽의 0 이하의 수, 오른쪽의 2 이상의 수끼리 서로 묶어주는 것이 유리하다는 것을 알 수 있음

// 이를 위해 정렬한 배열을 양쪽에서 묶어줄 l, r 커서를 마련, 묶어줄 두 수에 1 미만 / 1 초과인 수가 섞이지 않을 때까지 커서에서 만난 두 수를 묶어준다
// 이후 묶어주지 않은 수들을 모두 더해주면 그게 답