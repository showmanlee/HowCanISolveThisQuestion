// 공간을 만들어 봅시다
// https://www.acmicpc.net/problem/10471

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int l, n;
	cin >> l >> n;
	vector<int> v(n + 2);
	vector<bool> exist(l + 1);
	v[0] = 0;
	v[n + 1] = l;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n + 1; j++) {
			exist[v[j] - v[i]] = true;
		}
	}
	for (int i = 1; i <= l; i++) {
		if (exist[i]) {
			cout << i << ' ';
		}
	}
	cout << '\n';
}

// 1차원 공간의 넓이와 파티션의 위치가 주어질 때, 주어진 파티션을 설치하여 만들 수 있는 공간의 넓이들 구하기

// 0~파티션 위치~끝점을 오름차순으로 나열한 배열을 만든 후 만들 수 있는 순서쌍의 차를 모두 구한 후, 중복을 제거하여 출력한다