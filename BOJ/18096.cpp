// Арифметическая магия
// https://www.acmicpc.net/problem/18096

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	cout << 1 << '\n';
}

// n이 주어질 때 ((x+1) * (y+1) - xy - x -y) ^ n을 구하기
// 저 식을 정리하면... 
//    (xy + x + y + 1 - xy - x - y) ^ n
// == 1 ^ n
// 따라서 n이 뭘 넣든 간에 답은 1