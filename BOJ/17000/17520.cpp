// Balanced String
// https://www.acmicpc.net/problem/17520

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 1;
	for (int i = 0; i < (n + 1) / 2; i++)
		res = (res * 2) % 16769023;
	cout << res << '\n';
}

// 0과 1로 이루어진 문자열 중 0과 1의 개수 차이가 1 이하인 문자열을 균형잡힌 문자열이라 부를 때, 길이 n의 균형잡힌 문자열의 개수(% 16769023)은?

// 쉽게 생각하면, n칸의 문자열 중 어떤 숫자 하나 (n / 2)개가 들어갈 위치의 개수 * 2(01)를 묻는 문제와 같음
// 따라서 문제의 답은 2^((n + 1) / 2)