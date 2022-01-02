// 크면서 작은 수
// https://www.acmicpc.net/problem/2992

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	int res = 0;
	if (next_permutation(s.begin(), s.end()))
		res = stoi(s);
	cout << res << '\n';
}

// 주어진 정수와 숫자 구성이 같으면서 큰 값들 중 가장 작은 값 구하기
// 정수를 string으로 받고, 만약 next_permutation이 되면(순열화했을 때 다음 순열이 있다면) 해당 값을 출력하고, 아니면 0 출력
// 순열 구성 백트래킹을 이런 식으로 넘길 수 있다