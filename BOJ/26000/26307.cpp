// Correct
// https://www.acmicpc.net/problem/26307

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int a, b;
	cin >> a >> b;
	cout << ((a - 9) * 60 + b) << '\n';
}
 
// 현재 시각이 주어졌을 때, 9시 정각에서 몇 분 지났는지 계산하기

// 쉽게 계산할 수 있어요
