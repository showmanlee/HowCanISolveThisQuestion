// 강의평
// https://www.acmicpc.net/problem/34845

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n, x;
	cin >> n >> x;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		sum += p;
	}
	int res = 0;
	while (n * x > sum) {
		sum += 100;
		n++;
		res++;
	}
	cout << res << '\n';
}

// 주어진 점수의 평균에서 100점을 계속 더해 평균을 x점으로 만드는 최소 횟수 구하기