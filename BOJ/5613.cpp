// 계산기 프로그램
// https://www.acmicpc.net/problem/5613

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	bool ord = true;
	vector<int> opr;
	vector<char> ops;
	ops.push_back(' ');
	while (true) {
		if (ord) {
			int p;
			cin >> p;
			opr.push_back(p);
		}
		else {
			char c;
			cin >> c;
			if (c == '=')
				break;
			ops.push_back(c);
		}
		ord = !ord;
	}
	int res = opr[0];
	for (int i = 1; i < ops.size(); i++) {
		if (ops[i] == '+')
			res += opr[i];
		if (ops[i] == '-')
			res -= opr[i];
		if (ops[i] == '*')
			res *= opr[i];
		if (ops[i] == '/')
			res /= opr[i];
	}
	cout << res << '\n';
}

// 주어지는 순서대로 계산기 버튼을 누를 때, 최종 연산 결과 출력하기

// 앞에서부터 순서대로 연산해나가기 - 피연산자와 연산다를 교대로 입력받아 각자의 배열에 넣은 후, 두 배열을 하나의 인덱스로 순회하며 결과 만들기
// 첫 연산은 첫 피연산자를 넣는 것으로 시작, 그 이후로는 사이의 연산자에 따라 다음 피연산자 연산하기