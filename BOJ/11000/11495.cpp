// 피보나치 비스무리한 수열
// https://www.acmicpc.net/problem/14495

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<long long> f(n + 1);
	for (int i = 1; i <= n; i++)
		f[i] = 1;
	for (int i = 4; i <= n; i++)
		f[i] = f[i - 1] + f[i - 3];
	cout << f[n] << '\n';
}

// f[n] = f[n - 1] + f[n - 3]을 만족하는 수열의 n번째 수 구하기

// 일반 피보나치를 구하듯이 dp로 구해주기
// n이 3 이하일 경우를 대비해 모든 칸에 1을 뿌려주고 시작하기
// 수열값이 생각보다 크므로 long long 범위 안에서 처리