// 좋은 날 싫은 날
// https://www.acmicpc.net/problem/17211

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);

	int n, init;
	cin >> n >> init;
	double gg, gb, bg, bb;
	cin >> gg >> gb >> bg >> bb;
	vector<double> pbg(n), pbb(n);
	pbg[0] = (init == 1 ? bg : gg);
	pbb[0] = (init == 1 ? bb : gb);
	for (int i = 1; i < n; i++) {
		pbg[i] = pbg[i - 1] * gg + pbb[i - 1] * bg;
		pbb[i] = pbg[i - 1] * gb + pbb[i - 1] * bb;
	}
	printf("%.0f\n%.0f", round(pbg[n - 1] * 1000), round(pbb[n - 1] * 1000));
}

// 기분이 좋은 날의 다음 날도 기분이 좋은 날일 확률, 다음 날은 기분이 싫은 날일 확률, 기분이 싫은 날의 다음 날이 기분이 좋은 날일 확률, 다음 날도 기분이 싫은 날일 확률이 주어진다
// 오늘의 기분이 주어질 때, n일 뒤 기분이 좋을 확률과 그렇지 않은 확률을 * 1000해서 소수 첫째자리에서 반올림하여 출력하기

// 내일 기분이 A일 확률 - 오늘 기분에서 A가 될 확률의 합(AA + BA)
// 기분이 좋을 확률과 나쁠 확률을 따로 계산해간다 - dp 활용하기
// dp의 첫 칸은 현재 기분에 따라 주어진 확률을 그대로 대입하고, 이후부터는 (전날 현재 기분 * 유지 확률) + (전날 아닌 기분 * 바뀔 확률)을 기록해간다
// 결과 출력은 printf 기반으로 round(확률 * 1000)으로 처리 - cmath round는 소수 첫째자리에서 반올림 처리