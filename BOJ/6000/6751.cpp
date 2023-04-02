// From 1987 to 2013
// https://www.acmicpc.net/problem/6751

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int t = n + 1;
	while (true) {
		vector<int> v(10);
		int tt = t;
		bool res = true;
		while (tt > 0) {
			v[tt % 10]++;
			if (v[tt % 10] > 1) {
				res = false;
				break;
			}
			tt /= 10;
		}
		if (res) {
			cout << t << '\n';
			break;
		}
		t++;
	}
}

// 주어진 수보다 크고 숫자가 중복해서 들어가지 않은 가장 작은 정수 구하기

// 하나씩 올려가면서 구해봅시다... - 각 자릿수를 돌며 등장 횟수를 세고, 중복되지 않으면 통과