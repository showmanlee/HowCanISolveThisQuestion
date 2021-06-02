// 암기왕
// https://www.acmicpc.net/problem/2776

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
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int p;
			cin >> p;
			auto lb = lower_bound(v.begin(), v.end(), p);
			if (lb == v.end() || *lb != p)
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
	}
}

// 외우고 있는 수들이 주어졌을 때, 주어진 수를 외우고 있는지 확인하기

// 해시를 사용할 수도 있고, 이분탐색을 사용할 수도 있음 - 여기서는 이분탐색 lower_bound를 활용
// 외우고 있는 수를 받은 뒤 정렬하고, lower_bound를 돌려본다
// 만약 lower_bound로 얻은 배열 포인터가 end거나 주어진 값을 가리키지 않는다면 아웃, 아니면 OK
// 당연하겠지만 end는 그 어떤 원소도 가리키지 않음