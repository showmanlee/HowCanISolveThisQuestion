// 두 수의 합
// https://www.acmicpc.net/problem/3273

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
	int x;
	cin >> x;
	sort(v.begin(), v.end());
	int p1 = 0, p2 = n - 1;
	int res = 0;
	while (true) {
		if (p1 == p2)
			break;
		if (v[p1] + v[p2] == x)
			res++;
		if (v[p1] + v[p2] > x)
			p2--;
		else
			p1++;
	}
	cout << res << '\n';
}

// 수열에서 두 수를 뽑아서 합이 x가 되는 쌍의 개수는?
// 수열의 길이가 100000이라서 n^2로 접근할 수는 없음
// 따라서 이 문제에는 '투 포인터'를 적용해야 함 - 정렬된 배열의 시작점/끝점에 포인터를 두고 거리를 점점 좁혀나가는 것

// 만약 두 포인터가 가리키는 수의 합이 x면 결과에 누적
// 이후 덧셈 결과에 따라 x보다 크면(수의 감소가 필요하면) 큰쪽의 포인터를 왼쪽으로 이동하고, 그렇지 않으면 작은쪽의 포인터를 오른쪽으로 이동한다
// 수열에 수가 중복되지 않음이 보장되기 때문
// 이후 두 포인터가 만나면 탐색 종료 후 결과 출력