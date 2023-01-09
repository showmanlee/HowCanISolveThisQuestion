// Generations of Tribbles
// https://www.acmicpc.net/problem/9507

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<long long> fib(68);
	fib[0] = fib[1] = 1;
	fib[2] = 2;
	fib[3] = 4;
	for (int i = 4; i <= 67; i++) {
		fib[i] = fib[i - 1] + fib[i - 2] + fib[i - 3] + fib[i - 4];
	}
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int p;
		cin >> p;
		cout << fib[p] << '\n';
	}
}
 
// 변형 피보나치 수열의 형성 방식이 주어질 때, p번째 변형 피보나치 수 구하기

// 일반 피보나치 구하듯 dp로 구하면 됩니다