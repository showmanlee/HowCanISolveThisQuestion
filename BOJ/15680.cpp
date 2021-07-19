// 연세대학교
// https://www.acmicpc.net/problem/15680

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	if (n == 0)
		cout << "YONSEI\n";
	else
		cout << "Leading the Way to the Future\n";
}

// 0이 들어오면 학교명, 1이 들어오면 슬로건 출력하기

// 대소문자 주의하면서 조건문으로 출력하기