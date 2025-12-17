// 얼룩말과 사자
// https://www.acmicpc.net/problem/34759

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	cout << n * 2 << '\n';
}

// a/2마리씩 늘어나는 얼룩말을 사자 n마리가 1머리씩 잡아먹을 때, 얼룩말이 멸종되지 않게 하는 최소 마릿수 구하기