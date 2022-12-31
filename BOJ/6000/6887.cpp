// Squares
// https://www.acmicpc.net/problem/6887

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	float n;
	cin >> n;
	n = sqrt(n);
	cout << "The largest square has side length " << ((int)n) << ".\n";
}

// 정사각형 타일의 개수가 주어질 때, 해당 타일들로 만들 수 있는 정사각형의 한 변의 최대 길이 구하기

// int(sqrt(n))