// 피드백
// https://www.acmicpc.net/problem/18856

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << n << '\n';
	for (int i = 1; i < n; i++) {
		cout << i << ' ';
	}
	cout << 997 << '\n';
}

// 길이가 n이고, 2번째 원소가 2이며, 마지막 원소가 1000 이하의 소수인 증가하는 수열 출력하기

// 1000 이하의 수 중 가장 큰 소수는 997 - 이걸 마지막 원소로 하고, 나머지는 1부터 n-1까지 채워준다