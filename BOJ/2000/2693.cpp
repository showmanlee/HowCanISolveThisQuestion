// N번째 큰 수
// https://www.acmicpc.net/problem/2693

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, string> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		vector<int> v(10);
		for (int i = 0; i < 10; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		cout << v[7] << '\n';
	}
}

// 10개의 수 중 세 번째로 큰 수 구하기

// 10개의 수를 배열로 받고 정렬하여 세 번째로 큰(인덱스가 7인) 수 출력하기