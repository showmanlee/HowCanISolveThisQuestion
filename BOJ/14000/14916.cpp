// 거스름돈
// https://www.acmicpc.net/problem/14916

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int count = 0;
	while (n > 0) {
		if (n % 5 == 0) {
			count += n / 5;
			n = 0;
			break;
		}
		n -= 2;
		count++;
	}
	if (n != 0)
		count = -1;
	cout << count << '\n';
}

// 거스름돈을 2원과 5원으로 거슬러줄 때, 최소 몇 개가 필요한가?
// 5원으로 나누어떨어질 때까지 2원을 거슬러주다가, 나누어떨어지는 순간에 5원으로 거슬러주기
// 만약 이 과정에서 5원으로 끝까지 안 나누어떨어진다면 -1 판정
// (2, 4를 제외한 모든 케이스에서 5원으로 거슬러주는게 더 이득)