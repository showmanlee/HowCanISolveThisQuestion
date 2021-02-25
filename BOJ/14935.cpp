// FA
// https://www.acmicpc.net/problem/14935

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string x;
	cin >> x;
	for (int i = 0; i < 100; i++) {
		x = (int)((x[0] - '0') * x.length());
	}
	cout << (x.length() == 1 ? "FA" : "NFA") << '\n';
}

// 입력으로 주어진 수 x의 첫 자리와 수 x의 자리수를 곱한 결과를 반환하는 함수를 계속 돌렸을 때 일정 시점 이후로 동일한 결과가 나오는 경우 FA수라고 할 때, FA수 판별하기
// 위의 경우가 나오려면 x의 자리수가 1이 나오면 된다(x * 1 = x 반복) - 따라서 판정 역시 x의 길이가 1인가로 판정
// x가 100자리가 나오니 입력은 string으로 받기
// 곱한 결과는 최대 3자리수가 나오니 적당히만 돌리면 됨 - 100번 정도