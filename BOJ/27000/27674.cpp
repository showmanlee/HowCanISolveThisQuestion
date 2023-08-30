// A+B
// https://www.acmicpc.net/problem/27674

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		sort(s.begin(), s.end(), greater<char>());
		long long a = stoll(s);
		long long b = a % 10;
		a /= 10;
		cout << (a + b) << '\n';
	}
}

// 숫자로 이루어진 문자열이 주어질 때, 문자열의 숫자들을 뽑아 2개의 양의 정수로 만들어서 얻을 수 있는 합의 최댓값 구하기

// 이 상황에서 가장 큰 수를 만드는 방법은 내림차순으로 정렬하는 것 - 그 상황에서 맨 뒤의 숫자 하나를 떼서 더하면 됨