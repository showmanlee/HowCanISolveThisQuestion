// 양말 짝 맞추기
// https://www.acmicpc.net/problem/28431

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	vector<int> v(10);
	for (int i = 0; i < 5; i++) {
		int p;
		cin >> p;
		v[p]++;
	}
	for (int i = 0; i < 10; i++) {
		if (v[i] % 2 == 1) {
			cout << i << '\n';
		}
	}
}

// 0~9가 적힌 5개의 양말로 2쌍이 만들어질 때, 남은 양말 한짝의 번호 출력하기

// 양말 종류별 개수를 세서 나머지가 1이 나온 양말 번호 출력하기