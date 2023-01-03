// And the Winner Is... Ourselves!
// https://www.acmicpc.net/problem/17509

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> a(11), b(11);
	for (int i = 0; i < 11; i++) {
		cin >> a[i] >> b[i];
	}
	sort(a.begin(), a.end());
	int cnt = 0;
	int res = 0;
	for (int i = 0; i < 11; i++) {
		cnt += a[i];
		res += cnt + (20 * b[i]);
	}
	cout << res << '\n';
}
 
// 각 문제를 풀 수 있는 시간과 틀릴 횟수가 주어진 상황에서 각 문제당 해당 문제를 푸는데 걸린 시간 + 틀린 횟수 * 20의 패널티가 주어질 때, 패널티를 최소화한 결과는?

// 그러니까, 각 문제의 패널티는 (지금 문제 푸는 시간) + (지금 문제에서 틀린 횟수 * 20) + (지난 문제들 푸는 시간)
// 시간 패널티는 계속 누적됨 - 그러니까 푸는 시간이 1, 2, 3이고 그 순서대로 풀었을 떄, 받는 패널티는 (1) + (1 + 2) + (1 + 2 + 3)이 되는 것
// 이 상황에서 누적되는 패널티를 최소화하려면 오름차순으로 정렬해서 누적치를 최소화해야 함
// 그리고 틀린 횟수 패널티는 별도로 누적되지 않음 - 모든 문제를 풀어야 하므로 틀린 횟수 패널티는 어떻게 풀든 똑같이 가져가야 함
// 이를 고려해서 시간은 정렬해서 계산, 틀린 횟수는 그냥 총합으로 계산한다