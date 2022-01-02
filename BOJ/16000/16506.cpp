// CPU
// https://www.acmicpc.net/problem/16506

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int t = 0; t < n; t++) {
		string op;
		int d, a, b;
		cin >> op >> d >> a >> b;
		string res;
		if (op == "ADD")
			res = "00000";
		else if (op == "ADDC")
			res = "00001";
		else if (op == "SUB")
			res = "00010";
		else if (op == "SUBC")
			res = "00011";
		else if (op == "MOV")
			res = "00100";
		else if (op == "MOVC")
			res = "00101";
		else if (op == "AND")
			res = "00110";
		else if (op == "ANDC")
			res = "00111";
		else if (op == "OR")
			res = "01000";
		else if (op == "ORC")
			res = "01001";
		else if (op == "NOT")
			res = "01010";
		else if (op == "MULT")
			res = "01100";
		else if (op == "MULTC")
			res = "01101";
		else if (op == "LSFTL")
			res = "01110";
		else if (op == "LSFTLC")
			res = "01111";
		else if (op == "LSFTR")
			res = "10000";
		else if (op == "LSFTRC")
			res = "10001";
		else if (op == "ASFTR")
			res = "10010";
		else if (op == "ASFTRC")
			res = "10011";
		else if (op == "RL")
			res = "10100";
		else if (op == "RLC")
			res = "10101";
		else if (op == "RR")
			res = "10110";
		else if (op == "RRC")
			res = "10111";
		res += "0";
		for (int i = 4; i >= 1; i /= 2)
			res += to_string(d / i % 2);
		for (int i = 4; i >= 1; i /= 2)
			res += to_string(a / i % 2);
		if (op[op.length() - 1] == 'C') {
			for (int i = 8; i >= 1; i /= 2)
				res += to_string(b / i % 2);
		}
		else {
			for (int i = 4; i >= 1; i /= 2)
				res += to_string(b / i % 2);
			res += "0";
		}
		cout << res << '\n';
	}
}

// 주어진 어셈블리어 코드를 변환 공식에 따라 16비트 기계어로 변환하기

// 말 그대로 주어진 표에 적힌 것처럼 구현하면 됨 - 2진수 변환을 중심으로
// 깡구현