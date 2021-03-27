// 0 만들기
// https://www.acmicpc.net/problem/7490

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char bf[9];

void dfs(int x) {
	if (x == n - 1) {
		int res = 987654321, p = 1, op = -1;
		for (int i = 0; i < n - 1; i++) {
			if (bf[i] == ' ')
				p = p * 10 + (i + 2);
			else {
				if (res == 987654321)
					res = p;
				else
					res += (op == 1 ? p : -p);
				op = (bf[i] == '+' ? 1 : 2);
				p = (i + 2);
			}
		}
		res += (op == 1 ? p : -p);
		if (res == 0) {
			for (int i = 0; i < n - 1; i++)
				cout << (i + 1) << bf[i];
			cout << n << '\n';
		}
		return;
	}
	bf[x] = ' ';
	dfs(x + 1);
	bf[x] = '+';
	dfs(x + 1);
	bf[x] = '-';
	dfs(x + 1);
}

int main(void) {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		dfs(0);
		cout << '\n';
	}
}

// 1~n까지의 수에 공백(서로 붙이기)과 + -을 삽입해 0을 만드는 경우 출력하기
// 아스키 코드 순으로 정렬하기 - ' '+- 순으로 입력하면 됨
// 모든 기호가 다 맞춰졌으면 계산 시작 
// 결과, 피연산자(1), 연산자를 기억하는 변수 생성 - 초기화는 절대 나올 수 없는 값으로(0으로 하면 버그 발생 가능)
// 두 숫자 사이의 기호를 순회하며 ' '이면 피연산자에 붙여주고, 그렇지 않다면 연산
// 만약 결과값이 초기화된 값이면(아직 연산이 이루어지지 않았다면) 피연산자를 붙여주고, 그렇지 않다면(연산이 한 번이라도 이루어졌다면) 이전에 확보한 연산자로 피연산자를 결과값에 연산
// 이후 현재 연산자를 저장하고, 피연산자를 새로 저장한다
// 모든 기호를 순회한 후 남은 연산자와 피연산자를 연산시키면 연산 완료
// 그 결과가 0이면 순서대로 출력하면 됨