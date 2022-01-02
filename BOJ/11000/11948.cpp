// 과목선택
// https://www.acmicpc.net/problem/11948

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> abcd(4), ef(2);
	for (int& i : abcd)
		cin >> i;
	for (int& i : ef)
		cin >> i;
	sort(abcd.begin(), abcd.end());
	sort(ef.begin(), ef.end());
	cout << (abcd[1] + abcd[2] + abcd[3] + ef[1]) << '\n';
}

// a~d 중 3과목, e/f 중 1과목을 선택할 때, 최대 점수가 나오도록 선택한 결과는?
// abcd 중 큰 거 3개, ef 중 큰 거 하나