// 백발백준하는 명사수
// https://www.acmicpc.net/problem/22938

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	double ax, ay, ar, bx, by, br;
	cin >> ax >> ay >> ar >> bx >> by >> br;
	double len = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
	cout << (len < ar + br ? "YES" : "NO") << '\n';
}

// 원점 위치와 반지름 길이가 주어진 두 과녁이 서로 겹치는가?

// 두 점 사이의 거리가 두 반지름의 합보다 작다면 두 원이 서로 겹치는 것 