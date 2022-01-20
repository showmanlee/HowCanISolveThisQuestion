// 알고리즘 수업 - 알고리즘의 수행 시간 4
// https://www.acmicpc.net/problem/24265

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	long long res = (n * (n - 1)) / 2;
	cout << res << '\n' << 2 << '\n';
}

/*
MenOfPassion(A[], n) {
	sum <- 0;
	for i <- 1 to n - 1
		for j <- i + 1 to n
			sum <- sum + A[i] × A[j]; # 코드1
	return sum;
}
*/
// 이 코드에서 n이 주어질 때 코드의 수행 횟수와 시간 복잡도 지수 출력하기

// 1부터 n - 1까지 i가 진행되고, i + 1에서 n까지 j가 진행된다
// 따라서 시간 복잡도는 O(n^2), 실행 횟수는 1부터 n-1까지의 합