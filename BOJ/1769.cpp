// 3의 배수
// https://www.acmicpc.net/problem/1769

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int res = 0;
	while (s.length() != 1) {
		int p = 0;
		for (char c : s)
			p += c - '0';
		s = to_string(p);
		res++;
	}
	cout << res << '\n';
	if (s == "3" || s == "6" || s == "9")
		cout << "YES\n";
	else
		cout << "NO\n";
}

// 어떤 수의 자릿수들을 모두 더한 값이 3의 배수일 때 해당 수도 3의 배수라고 할 때, 이러한 방식으로 어떤 수를 한 자릿수로 만드는 과정의 수와 해당 수가 3의 배수인지 판정하기

// 어떤 수가 100만 자리까지 주어질 수 있으므로 문자열 기반으로 접근 - 어떤 수의 자릿수의 합은 int 범위 안임이 보장됨
// 수를 받고, 해당 수의 자릿수 합을 구한 뒤 그 값을 다시 문자열화하는 과정을 길이가 1이 될 때까지 반복
// 이후 그 결과가 3 6 9라면 YES, 그렇지 않으면 NO 출력