// 개표
// https://www.acmicpc.net/problem/10102

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v;
	cin >> v;
	int a = 0, b = 0;
	for (int i = 0; i < v; i++) {
		char c; 
		cin >> c;
		if (c == 'A')
			a++;
		else
			b++;
	}
	if (a == b)
		cout << "Tie";
	else if (a > b)
		cout << "A";
	else
		cout << "B";
	cout << '\n';
}

// 둘 중 더 많은 표를 받은 사람은?
// 그냥 글자 수를 세주면 됨 - 사람도 많지 않음