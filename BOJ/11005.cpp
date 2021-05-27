// 진법 전환 2
// https://www.acmicpc.net/problem/11005

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	char convert[36] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	int n, k;
	cin >> n >> k;
	string res;
	while (n > 0) {
		res = convert[n % k] + res;
		n /= k;
	}
	cout << res << '\n';
}

// 주어진 수를 k진법으로 바꾸기

// 나눗셈과 나머지를 반복하여 실행 - 미리 해당 숫자에 대응한 문자를 표시하는 배열을 만들어 활용