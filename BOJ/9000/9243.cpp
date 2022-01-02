// 파일 완전 삭제
// https://www.acmicpc.net/problem/9243

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		if (n % 2 == (s[i] != t[i]))
			res++;
	}
	cout << "Deletion " << (res == s.length() ? "succeeded" : "failed") << '\n';
}

// 어떤 파일의 비트에 반대 비트들로 n번 덮어씌울 때, 제대로 덮어씌워졌는지 확인하기

// n이 짝수라면 전과 후의 비트가 모두 같아야 하고, 홀수라면 모두 달라야 한다
// 이 조건에 모든 비트가 부합하는지 판정하고, 부합한다면 성공