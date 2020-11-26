// 쇠막대기
// https://www.acmicpc.net/problem/10799

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	cin >> s;
	int res = 0, count = 0;
	bool prev = false;
	for (char c : s) {
		if (c == '(') {
			count++;
			prev = true;
		}
		else {
			count--;
			if (prev) 
				res += count;
			else
				res++;
			prev = false;
		}
	}
	cout << res << '\n';
}

// 괄호 스택 문제
// 괄호가 닫힐 때, 레이저 형태가 나오면 그때까지 쌓인 막대기 수를 카운트에 넣고, 그렇지 않으면 끝나는 조각 1을 넣기
// 간단하니까 굳이 물리적인 스택을 안 만들어줘도 될 거 같은데