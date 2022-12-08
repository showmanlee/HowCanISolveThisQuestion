// Don’t pass me the ball!
// https://www.acmicpc.net/problem/6768

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	n--;
	cout << (n * (n - 1) * (n - 2) / 6) << '\n';
}

// 주어진 수보다 작은 자연수 3개를 골라 만들 수 있는 증가하는 수열의 개수 구하기

// n-1개 중 3개를 뽑는 조합의 개수 구하기 - nC3