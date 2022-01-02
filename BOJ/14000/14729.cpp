// 칠무해
// https://www.acmicpc.net/problem/14729

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);

	int n;
	scanf("%d", &n);
	vector<double> board(n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &board[i]);
	sort(board.begin(), board.end());
	for (int i = 0; i < 7; i++)
		printf("%.3lf\n", board[i]);
}

// 점수가 가장 낮은 7명의 점수 출력하기

// 평범하게 실수를 받아 정렬한 뒤 가장 낮은 7명을 소수 세 자리까지 출력하기 - 문제는 학생 수가 1천만 명
// 따라서 n^2 정렬이 아닌 nlogn 정렬을 도입해야 함 - sort(퀵)이나 stable_sort(병합) 같이