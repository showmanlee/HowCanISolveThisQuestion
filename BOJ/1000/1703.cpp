// 생장점
// https://www.acmicpc.net/problem/1703

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		int p = 1;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			p = p * a - b;
		}
		cout << p << '\n';
	}
}

// 가지 하나가 달린 나무에 가지 하나당 a개의 가지가 새로 달리고 그 중 b개의 가지를 자르는 과정을 반복할 때, 남은 가지의 개수 구하기

// a를 곱하고 b를 빼는 과정 반복하기