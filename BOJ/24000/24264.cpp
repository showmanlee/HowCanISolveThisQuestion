// 알고리즘 수업 - 알고리즘의 수행 시간 3
// https://www.acmicpc.net/problem/24264

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	cout << (n * n) << '\n' << 2 << '\n';
}

/*
MenOfPassion(A[], n) {
	sum <- 0;
	for i <- 1 to n
		for j <- 1 to n
			sum <- sum + A[i] × A[j]; # 코드
	return sum;
}
*/
// 이 코드에서 n이 주어질 때 코드의 수행 횟수와 시간 복잡도 지수 출력하기

// 1부터 n까지 진행하는 for가 2개 있으므로 저 코드는 n^2번 실행됨
// 따라서 시간 복잡도는 O(n^2)