// 01타일
// https://www.acmicpc.net/problem/1904

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	vector<int> pib;
	int n;
	cin >> n;
	pib.push_back(1);
	pib.push_back(1);
	for (int i = 2; i <= n; i++)
		pib.push_back((pib[i - 2] + pib[i - 1]) % 15746);
	cout << pib[n] << endl;
}

// 1 = 1 - 1
// 2 = 2 - 11 00
// 3 = 3 - 100 001 111
// 4 = 5 - 0000 0011 1001 1100 1111
// 5 = 8 - 00001 00100 10000 11100 11001 10011 00111 11111
// 6 = 13 - 000000 000011 001001 100001 001100 100100 110000 111100 111001 110011 100111 001111 111111
// 너도 피보나치구나