// Billing
// https://www.acmicpc.net/problem/5342

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
	cout.precision(2);

	float res = 0;
	while (true) {
		string s;
		cin >> s;
		if (s == "EOI") {
			break;
		}
		if (s == "Paper") {
			res += 57.99;
		} else if (s == "Printer")	{
			res += 120.50;
		} else if (s == "Planners") {
			res += 31.25;
		} else if (s == "Binders")	{
			res += 22.50;
		} else if (s == "Calendar") {
			res += 10.95;
		} else if (s == "Notebooks") {
			res += 11.20;
		} else if (s == "Ink")	{
			res += 66.95;
		}
	}
	cout << "$" << res << '\n';
}

// 구매한 물품 내역과 그 가격이 주어질 때, 물건의 총합 구하기

// 이름 받고 출력하기