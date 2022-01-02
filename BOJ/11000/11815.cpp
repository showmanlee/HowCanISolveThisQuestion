// 짝수? 홀수?
// https://www.acmicpc.net/problem/11815

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long p;
		cin >> p;
		long long pp = sqrt(p);
		cout << (p == pp * pp) << ' ';
	}
	cout << '\n';
}

// 주어진 수의 약수 개수가 홀수인지 짝수인지 판정하기

// 1 = 1
// 2 = 1 2
// 3 = 1 3
// 4 = 1 2 4
// 5 = 1 5
// 6 = 1 2 3 6
// 7 = 1 7
// 8 = 1 2 4 8
// 9 = 1 3 9
// 10 = 1 2 5 10
// 11 = 1 11
// 12 = 1 2 3 4 6 12
// 13 = 1 13
// 14 = 1 2 7 14
// 15 = 1 3 5 15
// 16 = 1 2 4 8 16
// (...)
// 이렇게 나열해놓고 보면, 약수를 정렬하여 반으로 접으면 마주보는 두 수의 곱이 원래 수가 되는 것을 볼 수 있음
// 그런데 만약 제곱수일 경우 반으로 접을 경우 제곱근이 중간에 걸리게 된다 - 따라서 어떤 수가 제곱수일 경우 약수는 홀수 개가 됨
// 따라서 제곱수 여부를 판별하여 제곱수면 1, 아니면 0 - 정밀도에 주의(sqrt를 정수화한 것을 다시 제곱하여 정수화)