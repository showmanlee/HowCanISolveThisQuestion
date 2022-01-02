// 카드 역배치
// https://www.acmicpc.net/problem/10804

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	vector<int> v(20);
	for (int i = 0; i < 20; i++)
		v[i] = i + 1;
	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		reverse(v.begin() + a - 1, v.begin() + b);
	}
	for (int i = 0; i < 20; i++)
		cout << v[i] << ' ';
	cout << '\n';
}

// 1부터 20까지 오름차순으로 놓인 카드들에 대해, 입력으로 주어진 10개의 구간 순서대로 뒤집는 작업을 했을 때 마지막 카드들의 배치 출력하기
// reverse를 활용해보자