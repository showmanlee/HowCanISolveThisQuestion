// IT Passport Examination
// https://www.acmicpc.net/problem/11257

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string s;
		int a, b, c;
		cin >> s >> a >> b >> c;
		int sum = a + b + c;
		cout << s << ' ' << sum << ' ' ;
		if (sum >= 55 && a >= 11 && b >= 8 && c >= 12) {
			cout << "PASS\n";	
		} else {
			cout << "FAIL\n";
		}
	}
}

// 총점이 35 / 25 / 40인 세 과목 시험에서 총점이 55점 이상이고 각 과목 점수가 30% 이상이어야 합격일 때, 합격 여부 판정하기

// 점수를 받아 계산해보고 판정해준다
// 각 과목 30%의 경우 소수가 나오긴 하나, 어쩄든 점수가 정수 단위로 나오므로 반올림해서 처리할 수 있음