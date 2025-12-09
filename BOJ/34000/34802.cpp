// 강의실 들어가기
// https://www.acmicpc.net/problem/34802

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	int sh = stoi(a.substr(0, 2));
	int sm = stoi(a.substr(3, 2));
	int ss = stoi(a.substr(6, 2));
	int eh = stoi(b.substr(0, 2));
	int em = stoi(b.substr(3, 2));
	int es = stoi(b.substr(6, 2));
	int n, m;
	cin >> n >> m;
	n = (n / 100) * (100 - m);
	int s = sh * 60 * 60 + sm * 60 + ss + n;
	int e = eh * 60 * 60 + em * 60 + es;
	cout << (s <= e) << '\n';
}

// 출발 및 도착 시간이 주어지고, 걷는데 걸리는 시간과 뛰어서 절약되는 시간이 주어질 때, 결과 구하기