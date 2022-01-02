// 소인수분해
// https://www.acmicpc.net/problem/11653

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<int> result;
	cin >> n;
	while (n > 1) {
		for (int i = 2; ; i++) {
			if (n % i == 0) {
				result.push_back(i);
				n /= i;
				break;
			}
		}
	}
	sort(result.begin(), result.end());
	for (int i : result)
		cout << i << '\n';
}

// 직접 소인수분해를 해보세요
// 이렇게 while문 기반으로 해도 풀림 - 1천만 이하