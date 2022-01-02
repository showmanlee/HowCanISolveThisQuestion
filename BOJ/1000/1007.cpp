// 벡터 매칭
// https://www.acmicpc.net/problem/1007

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		vector<pr> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second;
		vector<int> selector(n, -1);
		for (int i = n / 2; i < n; i++)
			selector[i] = 1;
		long long res = 987654321987654;
		do {
			long long sx = 0, sy = 0;
			for (int i = 0; i < n; i++) {
				sx += v[i].first * selector[i];
				sy += v[i].second * selector[i];
			}
			long long sum = sx * sx + sy * sy;
			res = min(sum, res);
		} while (next_permutation(selector.begin(), selector.end()));
		double resq = sqrt(res);
		printf("%lf\n", resq);
	}
}

// n(n % 2 == 0)개의 점을 2개씩 이은 벡터 집합의 합의 길이의 최솟값은?

// AB = OB - OA, 두 점을 이은 벡터를 더한다 = 한 점의 좌표를 더하고 다른 한 점의 좌표를 뺀다
// n은 최대 20, 브루트포스로 접근 가능한 문제 - next_permutation을 돌릴 수 있도록 더할 점 절반과 뺄 점 절반을 표시하는 배열 활용([-1, -1, 1, 1])
// next_permutaion을 돌면서 선택된 대로 합 좌표에 현재 좌표를 더하거나 뺀 뒤, 합 좌표의 길이의 제곱을 구한다 - 최솟값 탐색 과정에서 실수화하면 오류 가능성
// 그렇게 최소 길이의 제곱을 구한 뒤, 제곱근을 구하여 출력하기 - 확실한 소수점 출력을 위해 printf로 출력해주기