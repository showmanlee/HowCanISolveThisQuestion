// 추론
// https://www.acmicpc.net/problem/1731

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
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	bool isPlus = (v[2] - v[1]) == (v[1] - v[0]);
	if (isPlus) {
		cout << v[n - 1] + (v[1] - v[0]);
	}
	else {
		cout << v[n - 1] * (v[1] / v[0]);
	}
}

// 수열이 주어질 때 등비수열인지 등차수열인지 보고 다음 수 출력하기

// 수열 길이가 언제나 3 이상이기 때문에 1-0과 2-1의 값을 보고 알 수 있음 - 같다면 등차, 아니면 등비
// 이를 이용해 마지막 수에서 등차를 더하거나 등비를 곱해서 답 출력하기