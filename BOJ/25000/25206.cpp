// 너의 평점은
// https://www.acmicpc.net/problem/25206

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	float sum = 0, count = 0;
	string s;
	while (cin >> s) {
		float p;
		string rank;
		cin >> p >> rank;
		float t = 0;
		if (rank == "A+") {
			t = 4.5;
		} else if (rank == "A0") {
			t = 4.0;
		} else if (rank == "B+") {
			t = 3.5;
		} else if (rank == "B0") {
			t = 3.0;
		} else if (rank == "C+") {
			t = 2.5;
		} else if (rank == "C0") {
			t = 2.0;
		} else if (rank == "D+") {
			t = 1.5;
		} else if (rank == "D0") {
			t = 1.0;
		} else if (rank == "F") {
			t = 0.0;
		} else if (rank == "P") {
			continue;
		}
		count += p;
		sum += p * t;
	}
	cout << (sum / count) << '\n';
}

// 과목, 학점, 평점이 주어졌을 때, 전체 전공평점 구하기

// 전공평점 = sum(학점*평점) / sum(학점)인데, P 받은 과목은 계산에서 제외해야 함
// 이를 고려하여 합들을 구하고, 나눈 값을 출력한다
// 과목명은 모두 다름이 보장되기에 고려할 필요 없음 - while(cin)을 돌릴 때 앞에 추가 입력이 있을지 확인하는 정도