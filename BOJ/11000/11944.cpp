// NN
// https://www.acmicpc.net/problem/11944

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string n;
	int m;
	cin >> n >> m;
	int t = n.length() * stoi(n);
	if (t > m)
		t = m;
	for (int i = 0; i < t; i++)
		cout << n[i % n.length()];
	cout << '\n';
}

// N을 N번 출력한다. 단, 그 글자가 M글자 이상 나오면 M글자만 출력
// 최대 2016을 2016번 출력하고, 2016글자 이상 나오면 2016글자만 출력