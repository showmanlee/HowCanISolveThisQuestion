// 회전
// https://www.acmicpc.net/problem/23813

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	long long res = 0;
	for (int i = 0; i < s.length(); i++) {
		res += stoll(s);
		char c = s.back();
		s.pop_back();
		s = c + s;
	}
	cout << res << '\n';
}

// 어떤 자연수의 일의 자리 수를 맨 앞으로 붙이는 것을 회전이라 할 때, 어떤 자연수의 회전으로 구할 수 있는 모든 수의 합은?

// 자연수는 문자열로 받기 - 회전은 back()을 떼서 pop_back() 한 뒤 앞에 붙이는 방식으로
// 결과가 long long이 나올 수 있으므로 계산은 long long 기반으로 작성한다