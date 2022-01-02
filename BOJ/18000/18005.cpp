// Even or Odd?
// https://www.acmicpc.net/problem/18005

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	if (n % 2 == 0) {
		if ((n / 2) % 2 == 1) {
			res = 1;
		}
		else {
			res = 2;
		}
	}
	cout << res << '\n';
}

// n개의 연속된 정수를 뽑았을 때 무조건 홀수가 나오는지(1), 무조건 짝수가 나오는지(2), 둘 다 나올 수 있는지(0) 판정하기

// 가우스 선생님의 법칙을 따라가보자 - 양끝의 수들을 모두 더해서 결과 얻기
// 만약 n이 홀수라면 위치에 따라 달라짐(0) - 양끝의 수를 더하면 모두 짝수가 되고, 중간에 남은 숫자 하나에 따라 달라짐
// 만약 n이 짝수라면 양끝의 수를 더하면 모두 홀수가 됨(1-4, 2-3...)
// 따라서 더하는 쌍의 수가 홀수라면 무조건 홀수가 나오고(1), 아니면 짝수가 나옴(2)