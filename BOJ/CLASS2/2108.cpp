// 통계학
// https://www.acmicpc.net/problem/2108

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> freq(8001);
	long long sum = 0;
	for (int& i : arr) {
		cin >> i;
		sum += i;
		freq[i + 4000]++;
	}
	sort(arr.begin(), arr.end());
	double mean = sum / (double)n;
	vector<int> mode;
	int max = 1;
	for (int i = 0; i <= 8000; i++) {
		if (freq[i] > max) {
			mode.clear();
			max = freq[i];
		}
		if (freq[i] == max) {
			mode.push_back(i - 4000);
		}
	}
	cout << round(mean) << '\n';
	cout << arr[n / 2] << '\n';
	cout << (mode.size() == 1 ? mode[0] : mode[1]) << '\n';
	cout << (arr[n - 1] - arr[0]) << '\n';
}

// 산술평균, 중앙값, 최빈값, 범위 구하기
// 최빈값이 여러 개일 경우 두 번째로 작은 값을 출력해야 함에 주의
// vector에 최빈값들을 모아뒀다가 갱신되면 지우기 반복?

// CLASS 2 완료!