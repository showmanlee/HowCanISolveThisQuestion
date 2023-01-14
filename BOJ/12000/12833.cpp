// XORXORXOR
// https://www.acmicpc.net/problem/12833

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	if (c % 2) {
		a ^= b;
	}
	cout << a << '\n';
}
 
// a를 b로 c번 XOR 연산한 결과 출력하기

// ^= - 근데 이걸 쓰면 시간 초과(10억)
// xor는 서로 달라야 참, 같으면 아웃
// 그런데 xor을 반복해주면 알 수 있듯이 xor을 2번 하면 원래 수로 돌아온다
// 따라서 c번 돌릴 필요 없이, c%2번 돌리면 되는 것