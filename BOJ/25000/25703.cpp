// 포인터 공부
// https://www.acmicpc.net/problem/25703

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << "int a;\n";
	if (n >= 1) {
		cout << "int *ptr = &a;\n";
	}
	if (n >= 2) {
		cout << "int **ptr2 = &ptr;\n";
	}
	if (n >= 3) {
		for (int i = 3; i <= n; i++) {
			cout << "int ";
			for (int j = 0; j < i; j++) {
				cout << "*";
			}
			cout << "ptr" << i << " = &ptr" << (i - 1) << ";\n";
		}
	}
}

// n중 포인터 선언 방식 출력하기

// 조금 더 복잡한 반복 출력 문제
// a, ptr만 잘 처리해주고 나머지는 반복문으로 출력하기