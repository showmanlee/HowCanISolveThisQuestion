// Affine Cipher
// https://www.acmicpc.net/problem/11575

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		for (char c : s)
			cout << char(((a * (c - 'A') + b) % 26) + 'A');
		cout << '\n';
	}
}


// 알파벳을 0~25로 뒀을 때, (aX + b) % 26의 형태로 암호화되는 암호 체계로 a, b가 주어질 때 평문 암호화하기

// 실제로 해당 연산을 각 문자 별로 수행하기 - 들어오는 알파벳은 'A'를 빼주고, 출력할 때는 'A'를 더해서 출력