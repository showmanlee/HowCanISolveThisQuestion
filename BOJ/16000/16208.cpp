// 귀찮음
// https://www.acmicpc.net/problem/16208

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<long long> v(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		sum -= v[i];
		res += v[i] * sum;
	}
	cout << res << '\n';
}

// 주어진 쇠파이프를 다양한 길이의 조각들로 자를 때 한번 자를 때마다 생기는 두 조각 길이의 곱만큼의 비용이 들 때, 만들 수 있는 최소 비용은?

// 사실 어떻게 자르든 비용은 모두 같음 - 왜 그러냐?
// 2, 3, 4, 5의 길이로 자른다고 해보자 - 길이의 총합은 14
// 작은 순부터 자른다고 한다고 하면 (2 * (3 + 4 + 5)) + (3 * (4 + 5)) + (4 * 5)
// 큰 순부터 자른다고 하면 (5 * (4 + 3 + 2)) + (4 * (3 + 2)) + (3 * 2)
// 랜덤하게 자른다고 해도 (3 * (5 + 4 + 2)) + (5 * (4 + 2)) + (4 * 2)
// 이 식들을 보면 모두 값이 같다는 걸 알 수 있음(71) - 식을 변형해보면 어떤 조각은 자신을 제외한 나머지 조각들의 합을 곱하고, 다른 조각은 어떤 조각과 자신을 제외한 조각들의 합을 곱하고... 이 과정이 반복됨
// 따라서 굳이 정렬을 해줄 필요는 없음 - 저런 꼴로 한 번만 구해주면 됨
// 다만 n이 50만이므로 n^2로 가면 안 되고, 입력 시 미리 합을 구한 다음, n으로 돌면서 자신을 합에서 빼고 그 값과 자신을 곱한 값을 결과값에 누적시킨다