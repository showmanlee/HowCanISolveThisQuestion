// 막대기
// https://www.acmicpc.net/problem/1094

#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int res = 0;
	while (n > 0) {
		res += n % 2;
		n /= 2;
	}
	cout << res << '\n';
}

// 64cm 막대기를 절반으로 나누고 그 조각을 붙이는 과정을 통해 ncm의 막대기를 만들 때, 필요한 막대기 조각의 수는?
// n을 2진수로 바꾼 값의 1의 개수만큼 막대기가 필요하다 - 나머지/나누기 반복을 통한 결과 내기