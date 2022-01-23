// 알고리즘 수업 - 알고리즘의 수행 시간 5
// https://www.acmicpc.net/problem/24266

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	long long res = n * n * n;
	cout << res << '\n' << 3 << '\n';
}

/*
MenOfPassion(A[], n) {
	sum <- 0;
	for i <- 1 to n
		for j <- 1 to n
			for k <- 1 to n
				sum <- sum + A[i] × A[j] × A[k]; # 코드
	return sum;
}
*/
// 이 코드에서 n이 주어질 때 코드의 수행 횟수와 시간 복잡도 지수 출력하기

// 1부터 n까지 진행되는 for가 3개 중첩되어 있음
// 따라서 실행 횟수는 n^3, 시간복잡도는 O(n^3)