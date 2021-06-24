// 디지털시계
// https://www.acmicpc.net/problem/1942

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int t = 0; t < 3; t++) {
		string a, b;
		cin >> a >> b;
		for (char& c : a)
			if (c == ':')
				c = ' ';
		for (char& c : b)
			if (c == ':')
				c = ' ';
		int ah, am, as, bh, bm, bs;
		stringstream ssa(a), ssb(b);
		ssa >> ah >> am >> as;
		ssb >> bh >> bm >> bs;
		int res = 0;
		while (true) {
			int p = ah * 10000 + am * 100 + as;
			if (p % 3 == 0)
				res++;
			if (ah == bh && am == bm && as == bs)
				break;
			as++;
			if (as == 60) {
				as = 0;
				am++;
			}
			if (am == 60) {
				am = 0;
				ah++;
			}
			if (ah == 24)
				ah = 0;
		}
		cout << res << '\n';
	}
}

// 디지털 시계에 적힌 숫자 3개(시분초)를 그래도 이어붙어 정수를 만들었을 때, 주어진 시간 범위 안에서 등장하는 3의 배수의 수는?

// stringstream을 통해 파싱 - 두 개의 시간 문자열을 받고, 해당 문자열의 ':'을 ' '로 바꾼 다음 값들을 받는다
// 이후 시간을 1초씩 추가해가며 정수를 만들고, 이것이 3의 배수라면 결과값에 추가
// 모든 시간(시작/도착 시간 포함)을 탐색하면 결과 출력하기 - 이 과정을 3회 반복