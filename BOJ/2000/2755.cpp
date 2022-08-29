// 이번학기 평점은 몇점?
// https://www.acmicpc.net/problem/2755

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
	cout.precision(2);

    int n;
    cin >> n;
    int cnt = 0;
    float score = 0;
    for (int i = 0; i < n; i++) {
        string s, g;
        int p;
        cin >> s >> p >> g;
        cnt += p;
        if (g == "A+") {
			score += 4.3 * p;
		} else if (g == "A0") {
			score += 4.0 * p;
		} else if (g == "A-") {
			score += 3.7 * p;
		} else if (g == "B+") {
			score += 3.3 * p;
		} else if (g == "B0") {
			score += 3.0 * p;
		} else if (g == "B-") {
			score += 2.7 * p;
		} else if (g == "C+") {
			score += 2.3 * p;
		} else if (g == "C0") {
			score += 2.0 * p;
		} else if (g == "C-") {
			score += 1.7 * p;
		} else if (g == "D+") {
			score += 1.3 * p;
		} else if (g == "D0") {
			score += 1.0 * p;
		} else if (g == "D-") {
			score += 0.7 * p;
		} else if (g == "F") {
			score += 0.0 * p;
        }
    }
    float res = score / cnt;
    cout << res << '\n';
}

// 수강한 수업명, 학점, 성적이 주어졌을 때, 평점 구하기

// 또다른 평점 구하기 문제 - 구조는 쉽지만 조건문 쓰기가 귀찮은 문제
// 성적 * 학점의 합을 학점의 합으로 나눈 결과 출력하기