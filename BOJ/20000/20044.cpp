// Project Teams
// https://www.acmicpc.net/problem/20044

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n * 2);
	for (int i = 0; i < n * 2; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int res = 987654321;
	for (int i = 0; i < n; i++) {
		res = min(res, v[i] + v[n * 2 - i - 1]);
	}
	cout << res << '\n';
}

// 코딩 역량이 모두 다른 2n명의 학생을 2인 1조로 구성할 때, 팀간 역량의 합 차이가 가장 적도록 했을 때 가장 역량이 적은 팀은?

// 차이를 가장 적게 하려면 가장 높은 자 + 가장 낮은 자 -> 그 다음으로 높은 자 + 그 다음으로 낮은 자... 이런 식으로 구성해나가면 됨
// 실제로 역량들을 받고, 정렬한 뒤, 그 순서로 더한 값 중 가장 작은 값을 출력한다