// Who is in the middle?
// https://www.acmicpc.net/problem/6840

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> v(3);
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << v[1] << '\n';
}

// 주어진 세 수를 정렬했을 때 가운데에 있는 수 구하기

// 네 구할게요