// 뒤집힌 덧셈
// https://www.acmicpc.net/problem/1357

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string x, y;
	cin >> x >> y;

	string nx = "", ny = "";
	for (int i = x.length() - 1; i >= 0; i--)
		nx += x[i];
	for (int i = y.length() - 1; i >= 0; i--)
		ny += y[i];
	string r = to_string(stoi(nx) + stoi(ny)), result = "";
	for (int i = r.length() - 1; i >= 0; i--)
		result += r[i];
	cout << stoi(result) << endl;
}

// 1000을 뒤집어서 0001이 되는 상황에 주의