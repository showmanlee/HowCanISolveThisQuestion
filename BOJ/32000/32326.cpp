// Conveyor Belt Sushi
// https://www.acmicpc.net/problem/32326

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	int res = a * 3 + b * 4 + c * 5;
	cout << res << '\n';
}

// 3달러, 4달러, 5달러 접시를 먹은 갯수가 주어질 때, 총합 구하기