// e 계산
// https://www.acmicpc.net/problem/6376

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << "n e\n- -----------\n0 1\n1 2\n2 2.5\n";
	double e = 2.5;
	cout << fixed;
	cout.precision(9);
	for (int i = 3; i <= 9; i++) {
		double p = 1.0;
		for (int j = 2; j <= i; j++) {
			p /= j;
		}
		e += p;
		cout << i << ' ' << e << '\n';
	}
}

// e 계산 방식에서 n이 0~9일 때 결과 출력하기

// 반복 계산 - 그러나 정밀도 관련해서 체크해줘야 되는 부분이 있음
// n이 0~1일 때는 소수 없음, 2는 한 자리, 그 이후로는 아홉 자리를 넣어줘야 함
// 따라서 이를 고려하여 0~2일 때는 그냥 출력하고, 3부터는 9자리 정밀도로 출력해서 넣어준다