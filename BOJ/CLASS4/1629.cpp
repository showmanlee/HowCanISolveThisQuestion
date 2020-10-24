// 곱셈
// https://www.acmicpc.net/problem/1629

#include <iostream>
using namespace std;

int dq(int a, int b, int c) {
	if (b == 0)
		return 1;
	int p = dq(a, b / 2, c);
	int res = ((long long)p * p) % c;
	if (b % 2 == 1)
		res = (long long)res * a % c;
	return res;
}

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	cout << dq(a, b, c) << endl;
}

// 값이 INT_MAX까지 주어지는데 설마 A * B % C를 치거나 A = (A + A) % C를 B번 돌릴 생각하는 건 아니겠지?
// 분할정복으로 처리하면 문제 해결 -> 재귀함수
// 먼저 절반만 제곱한 값을 재귀를 통해 구한다(b == 0이 되면 1을 반환하며 브레이킹)
// 이후 그 값을 통해 완제곱 값을 구하게 되는데, 만약 제곱수가 홀수인 경우 여기에 한 번 더 곱해준다
// 여기서 int 범위를 초과할 수 있기 때문에 long long으로 캐스팅(c로 mod 연산을 해주기 때문에 값까지 long long으로 맞출 필요는 없음)
// 이것이 분할정복의 뼈대