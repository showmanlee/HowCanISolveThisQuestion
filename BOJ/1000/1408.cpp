// 24
// https://www.acmicpc.net/problem/1408

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	int ah = stoi(a.substr(0, 2));
	int am = stoi(a.substr(3, 2));
	int as = stoi(a.substr(6, 2));
	int bh = stoi(b.substr(0, 2));
	int bm = stoi(b.substr(3, 2));
	int bs = stoi(b.substr(6, 2));
	int rh = 0, rm = 0, rs = 0;
	rs = bs - as;
	if (rs < 0) {
		rs += 60;
		bm--;
	}
	rm = bm - am;
	if (rm < 0) {
		rm += 60;
		bh--;
	}
	rh = bh - ah;
	if (rh < 0) {
		rh += 24;
	}
	cout << (rh / 10 == 0 ? "0" : "") << rh << ':' << (rm / 10 == 0 ? "0" : "") << rm << ':' << (rs / 10 == 0 ? "0" : "") << rs << '\n';
}

// 아래 시각에서 위의 시각을 뺀 결과 출력하기

// 이런 시간 계산 문제는 발상은 쉽지만 그걸 변환하는 과정이 귀찮음
// 다른 언어에서는 시간 클래스를 이용해 계산할 수도 있지만 여기서는 안 되니