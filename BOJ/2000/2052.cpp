// 지수연산
// https://www.acmicpc.net/problem/2052

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	double res = pow(0.5, n);
	printf("%.*f\n", n, res);
}

// 1 / (2^n) 구하기 - 앞의 불필요한 0 없이 자리 끝까지

// (1/2)^n의 결과 자릿수는 소수 n째자리까지
// 출력이 지수 표기법으로 전환되지 않도록 해야 함 - python은 오히려 그걸 못함
// printf의 %.*f는 소수 표시 자릿수를 직접 인수로 줄 수 있음 - 이 방식으로 해결