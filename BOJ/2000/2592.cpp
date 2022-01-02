// 대표값
// https://www.acmicpc.net/problem/2592

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> count(100);
	int maxi = 0, maxn = 0, sum = 0;
	for (int i = 0; i < 10; i++) {
		int p;
		cin >> p;
		sum += p;
		count[p / 10]++;
		if (count[p / 10] > maxi) {
			maxi = count[p / 10];
			maxn = p;
		}
	}
	sum /= 10;
	cout << sum << '\n' << maxn << '\n';
}

// 자연수 10개의 평균과 최빈값 출력하기

// 10의 배수만 주어지기에 평균이 자연수임이 보장됨 - 따라서 평균은 주어진 10개의 수의 합 / 10을 출력
// 최빈값의 경우 카운팅 배열을 통해 등장 횟수를 세고, 등장 횟수 최고점이 갱신되면 해당 숫자를 최빈값으로 삼는다 - 등장 횟수가 같으면 어떤 수를 출력해도 됨