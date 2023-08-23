// 먹을 것인가 먹힐 것인가
// https://www.acmicpc.net/problem/7795

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		sort(a.begin(), a.end(), greater<int>());
		sort(b.begin(), b.end(), greater<int>());
		int idxb = 0;
		int res = 0;
		for (int i = 0; i < n; i++) {
			while (idxb < m && a[i] <= b[idxb]) {
				idxb++;
			}
			res += m - idxb;
		}
		cout << res << '\n';
	}
}

// 두 집합 a, b의 원소 하나씩을 뽑아 쌍을 만들 때, a의 원소가 b의 원소보다 큰 경우의 수 구하기

// 두 집합을 내림차순으로 정렬한 후, b의 원소를 가리키는 인덱스를 만들어 맨 앞에 둔다
// a의 원소를 순회하며 인덱스를 해당 원소보다 작은 원소 중 가장 앞에 원소에 두고, b에서 남은 원소 개수를 더해준다